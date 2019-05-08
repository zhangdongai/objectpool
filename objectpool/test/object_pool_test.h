#ifndef OBJECT_POOL_TEST_H
#define OBJECT_POOL_TEST_H

#include <iomanip>
#include <iostream>
#include <string>

#include "pool/object_pool.h"

class ObjectPoolTest {
public:
    ObjectPoolTest() :
        idata_(0),
        fdata_(10.0f),
        sdata_("__init__") {
//        std::cout << "constructor without parameters is called" << std::endl;
    }

    ObjectPoolTest(const int32_t i, const float f, const std::string& s) :
        idata_(i),
        fdata_(f),
        sdata_(s) {
//        std::cout << "constructor with parameters is called" << std::endl;
    }

    void format_out() const {
        std::cout << "idata_ = " << std::setw(4) << idata_ << std::endl;
        std::cout << "fdata_ = " << std::setw(4) << fdata_ << std::endl;
        std::cout << "sdata_ = " << sdata_ << std::endl;
    }
private:
    int32_t idata_;
    float fdata_;
    std::string sdata_;
};

OBJPOOL_DECL(ObjectPoolTest);

#endif