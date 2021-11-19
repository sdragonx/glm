/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 logical.hpp

 2021-11-19 13:27:46

*/
#ifndef LOGICAL_HPP_20211119132746
#define LOGICAL_HPP_20211119132746

#include "../vec.hpp"
#include "functional.hpp"

namespace cgl{
namespace glm{


//
// Logical operation
//

template<typename T>
GLM_API bool lessThan(const T& x, const T& y)
{
    return x < y;
}

template<typename T>
GLM_API bool lessThanEqual(const T& x, const T& y)
{
    return x <= y;
}

template<typename T>
GLM_API bool greaterThan(const T& x, const T& y)
{
    return x > y;
}

template<typename T>
GLM_API bool greaterThanEqual(const T& x, const T& y)
{
    return x >= y;
}

template<typename T>
GLM_API bool equal(const T& x, const T& y)
{
    return x == y;
}

template<typename T>
GLM_API bool notEqual(const T& x, const T& y)
{
    return x != y;
}

//
// vec<N, T>
//

template<size_t N, typename T>
GLM_API vec<N, T> lessThan(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute(lessThan, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> lessThanEqual(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute(lessThanEqual, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> greaterThan(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute(greaterThan, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> greaterThanEqual(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute(greaterThan, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> equal(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute(equal, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> notEqual(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute(notEqual, x, y);
}

template<size_t N, typename T>
GLM_API bool any(const vec<N, T>& v)
{
    for (size_t i = 0; i < N; ++i) {
        if (v[i] == true) {
            return true;
        }
    }
    return false;
}

template<size_t N, typename T>
GLM_API bool all(const vec<N, T>& v)
{
    for (size_t i = 0; i < N; ++i) {
        if (v[i] == false) {
            return false;
        }
    }
    return true;
}

template<size_t N, typename T>
GLM_API vec<N, T> Not(const vec<N, T>& v)
{
    vec<N, T> product;
    for (size_t i = 0; i < N; ++i) {
        product[i] = !v[i];
    }
    return product;
}

}// end namespace glm
}// end namespace cgl

#endif// LOGICAL_HPP_20211119132746
