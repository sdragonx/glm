/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 float.hpp

 2022-02-25 14:15:15

*/
#ifndef GLM_FLOAT_HPP_20220225141515
#define GLM_FLOAT_HPP_20220225141515

#include "type_traits.hpp"

namespace glm {

template<typename T>
GLM_API bool isfinite(const T& value)
{
    return type_traits<T>::isfinite(value);
}

template<typename T>
GLM_API bool isinf(const T& value)
{
    return type_traits<T>::isinf(value);
}

template<typename T>
GLM_API bool isnan(const T& value)
{
    return type_traits<T>::isnan(value);
}

template<typename T>
GLM_API bool isnormal(const T& value)
{
    return type_traits<T>::isnormal(value);
}

template<typename T>
GLM_API bool signbit(const T& value)
{
    return type_traits<T>::signbit(value);
}

} // end namespace cgl

#endif // GLM_FLOAT_HPP_20220225141515
