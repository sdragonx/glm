/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 logical.hpp

 2021-11-19 13:27:46

*/
#ifndef GLM_LOGICAL_HPP_20211119132746
#define GLM_LOGICAL_HPP_20211119132746

#include "functional.hpp"
#include "functions.hpp"
#include "type_traits.hpp"



namespace glm {

//
// Logical operation
//

template<typename T>
GLM_API bool Not(const T& value)
{
    return type_traits<T>::Not(value);
}

template<typename T>
GLM_API bool lessThan(const T& x, const T& y)
{
    return type_traits<T>::less(x, y);
}

template<typename T>
GLM_API bool lessThanEqual(const T& x, const T& y)
{
    return type_traits<T>::lessEqual(x, y);
}

template<typename T>
GLM_API bool greaterThan(const T& x, const T& y)
{
    return type_traits<T>::greater(x, y);
}

template<typename T>
GLM_API bool greaterThanEqual(const T& x, const T& y)
{
    return type_traits<T>::greaterEqual(x, y);
}

template<typename T>
GLM_API bool equal(const T& x, const T& y)
{
    return type_traits<T>::equal(x, y);
}

template<typename T>
GLM_API bool notEqual(const T& x, const T& y)
{
    return type_traits<T>::notEqual(x, y);
}

//
// vec<N, T>
//

template<size_t N, typename T>
GLM_API vec<N, bool> lessThan(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>(lessThan<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, bool> lessThanEqual(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>(lessThanEqual<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, bool> greaterThan(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>(greaterThan<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, bool> greaterThanEqual(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>(greaterThan<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, bool> equal(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>(equal<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, bool> notEqual(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>(notEqual<T>, x, y);
}

template<size_t N, typename T>
GLM_API bool any(const vec<N, T>& v)
{
    for (size_t i = 0; i < N; ++i) {
        if (!Not<T>(v[i])) {
            return true;
        }
    }
    return false;
}

template<size_t N, typename T>
GLM_API bool all(const vec<N, T>& v)
{
    for (size_t i = 0; i < N; ++i) {
        if (Not<T>(v[i])) {
            return false;
        }
    }
    return true;
}

template<size_t N, typename T>
GLM_API vec<N, bool> Not(const vec<N, T>& v)
{
    return compute<bool, N, T>(Not<T>, v);
}

}// end namespace glm

#endif// GLM_LOGICAL_HPP_20211119132746
