/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 trigonometric.hpp

 2022-02-26 04:23:07

*/
#ifndef GLM_VECTOR_TRIGONOMETRIC_HPP_20220226042307
#define GLM_VECTOR_TRIGONOMETRIC_HPP_20220226042307

#include "detail/functional.hpp"
#include "detail/trigonometric.hpp"



namespace glm {

template<size_t N, typename T>
GLM_API vec<N, T> radians(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(radians<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> degrees(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(degrees<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> sin(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(sin<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> cos(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(cos<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> tan(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(tan<T>, v);
}

// [-PI/2, PI/2]
template<size_t N, typename T>
GLM_API vec<N, T> asin(const vec<N, T>& v)
{
    return compute<T, N, T>::asin(radians<T>, v);
}

// [0, PI]
template<size_t N, typename T>
GLM_API vec<N, T> acos(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(acos<T>, v);
}

// [-PI, PI]
template<size_t N, typename T>
GLM_API vec<N, T> atan(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(atan<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> atan(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>::invoke(atan<T>, x, y);
}

}// end namespace glm

#endif// GLM_VECTOR_TRIGONOMETRIC_HPP_20220226042307
