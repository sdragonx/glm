/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 vector_logical.hpp

 2022-02-21 00:19:19

*/
#ifndef GLM_VECTOR_LOGICAL_HPP_20220221001919
#define GLM_VECTOR_LOGICAL_HPP_20220221001919

#include "../detail/functional.hpp"
#include "../detail/logical.hpp"



namespace glm {

//
// vec<N, T>
//

template<size_t N, typename T>
GLM_API vec<N, bool> lessThan(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>::invoke(type_traits<T>::less, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, bool> lessThanEqual(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>::invoke(type_traits<T>::lessEqual, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, bool> greaterThan(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>::invoke(type_traits<T>::greater, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, bool> greaterThanEqual(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>::invoke(type_traits<T>::greaterEqual, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, bool> equal(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>::invoke(type_traits<T>::equal, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, bool> notEqual(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<bool, N, T>::invoke(type_traits<T>::notEqual, x, y);
}

template<size_t N>
GLM_API bool any(const vec<N, bool>& v)
{
    return logical_or<N, bool>::invoke(type_traits<bool>::judge, v);
}

template<size_t N>
GLM_API bool all(const vec<N, bool>& v)
{
    return logical_and<N, bool>::invoke(type_traits<bool>::judge, v);
}

template<size_t N>
GLM_API vec<N, bool> not_(const vec<N, bool>& v)
{
    return compute<bool, N, bool>::invoke(type_traits<bool>::Not, v);
}

//
// operator
//

template<size_t N, typename T>
GLM_API bool operator == (const vec<N, T>& x, const vec<N, T>& y)
{
    return logical_and<N, T>::invoke(type_traits<T>::equal, x, y);
}

template<size_t N, typename T>
GLM_API bool operator != (const vec<N, T>& x, const vec<N, T>& y)
{
    return logical_or<N, T>::invoke(type_traits<T>::notEqual, x, y);
}

}// end namespace glm

#endif// GLM_VECTOR_LOGICAL_HPP_20220221001919
