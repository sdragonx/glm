/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 vector_functions.hpp

 2022-02-25 04:04:16

*/
#ifndef GLM_VECTOR_FUNCTIONS_HPP_20220225040416
#define GLM_VECTOR_FUNCTIONS_HPP_20220225040416

#include "../detail/functional.hpp"
#include "../detail/functions.hpp"



namespace glm {

template<size_t N, typename T>
GLM_API vec<N, bool> isinf(const vec<N, T>& v)
{
    return compute<bool, N, T>::invoke(glm::isinf<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, bool> isnan(const vec<N, T>& v)
{
    return compute<bool, N, T>::invoke(isnan<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> abs(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(abs<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> ceil(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(ceil<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> clamp(const vec<N, T>& v, T minVal, T maxVal)
{
    return compute<T, N, T>::invoke(clamp<T, T>, v, minVal, maxVal);
}

template<size_t N, typename T>
GLM_API vec<N, T> exp(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(exp<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> exp2(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(exp2<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> floor(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(floor<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> fract(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(fract<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> max(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>::invoke(max<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> mid(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>::invoke(mid<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> min(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>::invoke(min<T>, x, y);
}

template<size_t N, typename T, typename A>
GLM_API vec<N, T> mix(const vec<N, T>& x, const vec<N, T>& y, A a)
{
    return compute<T, N, T>::invoke(mix<T>, x, y, static_cast<T>(a));
}

template<size_t N, typename T>
GLM_API vec<N, T> mod(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>::invoke(mod<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> mod(const vec<N, T>& x, const T& y)
{
    return compute<T, N, T>::invoke(mod<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> modf(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>::invoke(modf<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> pow(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>::invoke(pow<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> round(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(round<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> sign(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(sign<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> sqrt(const vec<N, T>& v)
{
    return compute<T, N, T>::invoke(sqrt<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> step(const T& edge, const vec<N, T>& x)
{
    return compute<T, N, T>::invoke(step<T>, edge, x);
}

template<size_t N, typename T>
GLM_API vec<N, T> step(const vec<N, T>& edge, const vec<N, T>& x)
{
    return compute<T, N, T>::invoke(step<T>, edge, x);
}

template<size_t N, typename T>
GLM_API vec<N, T> smoothstep(const vec<N, T>& edge0, const vec<N, T>& edge1, const vec<N, T>& x)
{
    return compute<T, N, T>::invoke(smoothstep<T>, edge0, edge1, x);
}

template<size_t N, typename T>
GLM_API vec<N, T> smoothstep(const T& edge0, const T& edge1, const vec<N, T>& x)
{
    return compute<T, N, T>::invoke(smoothstep<T>, vec<N, T>(edge0), vec<N, T>(edge1), x);
}

}// end namespace glm

#endif// GLM_VECTOR_FUNCTIONS_HPP_20220225040416
