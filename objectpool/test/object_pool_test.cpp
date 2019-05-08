#include "object_pool_test.h"

#ifdef __GNUC__
#include <unordered_map>
#include "gtest/gtest.h"

class ObjectPoolUnitTest : public ::testing::Test {
public:
    ObjectPoolUnitTest() {}
    virtual ~ObjectPoolUnitTest() {}

    virtual void SetUp() {}
protected:
    std::unordered_map<int32_t, int32_t> address_map_;
};

TEST_F(ObjectPoolUnitTest, ObjectAddress) {
    for (int32_t i = 0; i < 32; ++i) {
        ObjectPoolTestPtr objptr = OBJPOOL_ALLOC(ObjectPoolTest);
        char c_addr[64] = { 0 };
        snprintf(c_addr, 64, "%u", objptr.get());
        int32_t i_addr = std::stoi(c_addr);
        address_map_[i_addr] = i;
    }
    ObjectPoolTestPtr objptr = OBJPOOL_ALLOC(ObjectPoolTest);
    char c_addr[64] = { 0 };
    snprintf(c_addr, 64, "%u", objptr.get());
    int32_t i_addr = std::stoi(c_addr);
    EXPECT_TRUE(address_map_.find(i_addr) != address_map_.end());

    objptr = OBJPOOL_ALLOC(ObjectPoolTest);
    snprintf(c_addr, 64, "%u", objptr.get());
    i_addr = std::stoi(c_addr);
    EXPECT_TRUE(address_map_.find(i_addr) != address_map_.end());
}
#endif // __GNUC__

int main(int argc, char** argv) {
#ifdef __GNUC__
    testing::InitGoogleTest(&argc, argv);
#endif // __GNUC__

    ObjectPoolTestPtr objptr = OBJPOOL_ALLOC(ObjectPoolTest);
    objptr->format_out();

    objptr = OBJPOOL_ALLOC(ObjectPoolTest, 132, 543.1f, "parameters");
    objptr->format_out();

#ifndef __GNUC__
    system("pause");
#endif // __GNUC__

#ifndef __GNUC__
    return 0;
#else
    return RUN_ALL_TESTS();
#endif // __GNUC__
}