#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include <memory>
#include <vector>
#include <list>
#include <mutex>
#include <utility>

template <typename ElemType_,
          bool PreAllocate_ = true,
          int32_t AllocCount_ = 32>
class ObjectPool {
public:
    enum class ElemState {
        INITALIZED = -1,
        IDLE = 0,
        OCCUPIED = 1,
    };
    using ElemPtr_ = std::shared_ptr<ElemType_>;
    using ElemUnit_ = std::pair<ElemPtr_, ElemState>;
    using ElemCont_ = std::vector<ElemUnit_>;
    using ElemIdle_Cont_ = std::list<int32_t>;

public:
    ~ObjectPool() {}

    static ObjectPool* instance() {
        static ObjectPool instance;
        return &instance;
    }

    template <typename... Args>
    ElemPtr_ Construct(Args&&... args) {
        std::lock_guard<std::mutex> lock(mutex_);
        CheckConstruct();

        const int index = elem_idle_cont_.front();
        elem_idle_cont_.pop_front();

        if (elem_cont_[index].second != ElemState::INITALIZED)
            new(elem_cont_[index].first.get()) ElemType_(std::forward<Args>(args)...);
        elem_cont_[index].second = ElemState::OCCUPIED;

        ElemPtr_ elem_ptr = elem_cont_[index].first;
        return elem_ptr;
    }

private:
    void PreAllocate() {
        Allocate();
    }

    void CheckConstruct() {
        if (elem_idle_cont_.empty()) {
            Recycle();
        }

        if (elem_idle_cont_.empty()) {
            Allocate();
        }
    }

    void Allocate() {
        for (int32_t i = 0; i < alloc_count_; ++i) {
            ElemPtr_ elem_ptr(new ElemType_);
            elem_cont_.push_back(std::make_pair(elem_ptr, ElemState::INITALIZED));
            elem_idle_cont_.push_back((int32_t)elem_cont_.size() - 1);
        }

        size_ = (int32_t)elem_cont_.size();
    }

    void Recycle() {
        for (int32_t i = 0; i < size_; ++i) {
            if (elem_cont_[i].first.unique()) {
                elem_idle_cont_.push_back(i);
                elem_cont_[i].second = ElemState::IDLE;
                elem_cont_[i].first->ElemType_::~ElemType_();
            }
        }
    }


private:
    ElemCont_ elem_cont_;
    ElemIdle_Cont_ elem_idle_cont_;
    bool pre_allocate_;
    int32_t size_;
    int32_t alloc_count_;
    std::mutex mutex_;

private:
    ObjectPool() {
        alloc_count_ = AllocCount_;
        pre_allocate_ = PreAllocate_;
        if (pre_allocate_) {
            PreAllocate();
        }
    }
    ObjectPool(const ObjectPool&);
    ObjectPool& operator = (const ObjectPool&);
};

#define OBJPOOL_DECL(TYPE, ...) \
    using TYPE##Pool = ObjectPool<TYPE, ##__VA_ARGS__>; \
    using TYPE##Ptr = std::shared_ptr<TYPE>;
#define OBJPOOL_INST(TYPE) \
    TYPE##Pool::instance()
#define OBJPOOL_ALLOC(TYPE, ...) \
    OBJPOOL_INST(TYPE)->Construct(__VA_ARGS__);

#endif // OBJECT_POOL_H
