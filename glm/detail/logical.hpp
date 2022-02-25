/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 logical.hpp

 2021-11-19 13:27:46

*/
#ifndef GLM_LOGICAL_HPP_20211119132746
#define GLM_LOGICAL_HPP_20211119132746

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
GLM_API bool not_(const T& value)
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

}// end namespace glm

#endif// GLM_LOGICAL_HPP_20211119132746
