template <typename T0>
ElemPtr_ Construct(T0& t0) { 
    std::lock_guard<std::mutex> lock(mutex_); 
    CheckConstruct();

    const int index = elem_idle_cont_.front();
    elem_idle_cont_.pop_front();
      
    new(elem_cont_[index].first.get()) ElemType_(t0);
    elem_cont_[index].second = ElemState::OCCUPIED;

    ElemPtr_ elem_ptr = elem_cont_[index].first;
    return elem_ptr;
}

template <typename T0>
ElemPtr_ Construct(const T0& t0) {
    std::lock_guard<std::mutex> lock(mutex_);
    CheckConstruct();

    const int index = elem_idle_cont_.front();
    elem_idle_cont_.pop_front();

    new(elem_cont_[index].first.get()) ElemType_(t0);
    elem_cont_[index].second = ElemState::OCCUPIED;

    ElemPtr_ elem_ptr = elem_cont_[index].first;
    return elem_ptr;
}

template <typename T0, typename T1>
ElemPtr_ Construct(T0& t0, T1& t1) { 
    std::lock_guard<std::mutex> lock(mutex_); 
    CheckConstruct();

    const int index = elem_idle_cont_.front();
    elem_idle_cont_.pop_front();
      
    new(elem_cont_[index].first.get()) ElemType_(t0, t1);
    elem_cont_[index].second = ElemState::OCCUPIED;

    ElemPtr_ elem_ptr = elem_cont_[index].first;
    return elem_ptr;
}

template <typename T0, typename T1>
ElemPtr_ Construct(const T0& t0, const T1& t1) {
    std::lock_guard<std::mutex> lock(mutex_);
    CheckConstruct();

    const int index = elem_idle_cont_.front();
    elem_idle_cont_.pop_front();

    new(elem_cont_[index].first.get()) ElemType_(t0, t1);
    elem_cont_[index].second = ElemState::OCCUPIED;

    ElemPtr_ elem_ptr = elem_cont_[index].first;
    return elem_ptr;
}

template <typename T0, typename T1, typename T2>
ElemPtr_ Construct(T0& t0, T1& t1, T2& t2) {  
    std::lock_guard<std::mutex> lock(mutex_);
    CheckConstruct();

    const int index = elem_idle_cont_.front();
    elem_idle_cont_.pop_front();
      
    new(elem_cont_[index].first.get()) ElemType_(t0, t1, t2);
    elem_cont_[index].second = ElemState::OCCUPIED;

    ElemPtr_ elem_ptr = elem_cont_[index].first;
    return elem_ptr;
}

template <typename T0, typename T1, typename T2>
ElemPtr_ Construct(const T0& t0, const T1& t1, const T2& t2) {
    std::lock_guard<std::mutex> lock(mutex_);
    CheckConstruct();

    const int index = elem_idle_cont_.front();
    elem_idle_cont_.pop_front();

    new(elem_cont_[index].first.get()) ElemType_(t0, t1, t2);
    elem_cont_[index].second = ElemState::OCCUPIED;

    ElemPtr_ elem_ptr = elem_cont_[index].first;
    return elem_ptr;
}

template <typename T0, typename T1, typename T2, typename T3>
ElemPtr_ Construct(T0& t0, T1& t1, T2& t2, T3& t3) {  
    std::lock_guard<std::mutex> lock(mutex_);
    CheckConstruct();

    const int index = elem_idle_cont_.front();
    elem_idle_cont_.pop_front();
      
    new(elem_cont_[index].first.get()) ElemType_(t0, t1, t2, t3);
    elem_cont_[index].second = ElemState::OCCUPIED;

    ElemPtr_ elem_ptr = elem_cont_[index].first;
    return elem_ptr;
}

template <typename T0, typename T1, typename T2, typename T3>
ElemPtr_ Construct(const T0& t0, const T1& t1, const T2& t2, const T3& t3) {
    std::lock_guard<std::mutex> lock(mutex_);
    CheckConstruct();

    const int index = elem_idle_cont_.front();
    elem_idle_cont_.pop_front();

    new(elem_cont_[index].first.get()) ElemType_(t0, t1, t2, t3);
    elem_cont_[index].second = ElemState::OCCUPIED;

    ElemPtr_ elem_ptr = elem_cont_[index].first;
    return elem_ptr;
}

template <typename T0, typename T1, typename T2, typename T3, typename T4>
ElemPtr_ Construct(T0& t0, T1& t1, T2& t2, T3& t3, T4& t4) {  
    std::lock_guard<std::mutex> lock(mutex_);
    CheckConstruct();

    const int index = elem_idle_cont_.front();
    elem_idle_cont_.pop_front();
      
    new(elem_cont_[index].first.get()) ElemType_(t0, t1, t2, t3, t4);
    elem_cont_[index].second = ElemState::OCCUPIED;

    ElemPtr_ elem_ptr = elem_cont_[index].first;
    return elem_ptr;
}

template <typename T0, typename T1, typename T2, typename T3, typename T4>
ElemPtr_ Construct(const T0& t0, const T1& t1, const T2& t2, const T3& t3, const T4& t4) {
    std::lock_guard<std::mutex> lock(mutex_);
    CheckConstruct();

    const int index = elem_idle_cont_.front();
    elem_idle_cont_.pop_front();

    new(elem_cont_[index].first.get()) ElemType_(t0, t1, t2, t3, t4);
    elem_cont_[index].second = ElemState::OCCUPIED;

    ElemPtr_ elem_ptr = elem_cont_[index].first;
    return elem_ptr;
}