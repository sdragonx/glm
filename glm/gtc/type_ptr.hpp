/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 type_ptr.hpp

 2021-11-16 00:44:41

*/
#ifndef GLM_TYPE_PTR_HPP_20211116004441
#define GLM_TYPE_PTR_HPP_20211116004441

#include "../mat4.hpp"

namespace cgl{
namespace glm{

template<typename T>
T* value_ptr(T& value)
{
    return &value;
}

template<typename T>
const T* value_ptr(const T& value)
{
    return &value;
}

template<size_t N, typename T>
T* value_ptr(vec<N, T>& v)
{
    return &v[0];
}

template<size_t N, typename T>
const T* value_ptr(const vec<N, T>& v)
{
    return &v[0];
}

template<size_t CX, size_t CY, typename T>
T* value_ptr(mat<CX, CY, T>& m)
{
    return value_ptr(m[0]);
}

template<size_t CX, size_t CY, typename T>
const T* value_ptr(const mat<CX, CY, T>& m)
{
    return value_ptr(m[0]);
}

}// end namespace glm
}// end namespace cgl

#endif// GLM_TYPE_PTR_HPP_20211116004441
