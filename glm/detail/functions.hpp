/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 functions.hpp

 2021-11-16 11:45:17

isinf
isnan
step
smoothstep
roundEven
matrixCompMult

*/
#ifndef GLM_FUNCTIONS_HPP_20211116114517
#define GLM_FUNCTIONS_HPP_20211116114517

#include "functional.hpp"

#ifdef min
    #undef min
#endif

#ifdef max
    #undef max
#endif



namespace glm{

template<typename T>
GLM_API T abs(const T& value)
{
    return value < static_cast<T>(0) ? -value : value;
}

template<typename T>
GLM_API T ceil(const T& value)
{
    return static_cast<T>(std::ceil(static_cast<double>(value)));
}

template<typename T, typename argT>
GLM_API T clamp(const T& value, const argT& minVal, const argT& maxVal)
{
    return min<T>(max<T>(value, minVal), maxVal);
}

template<typename T>
GLM_API T exp(const T& value)
{
    return static_cast<T>(std::exp(static_cast<double>(value)));
}

template<typename T>
GLM_API T exp2(const T& value)
{
    static_cast<T>(std::exp2(static_cast<double>(value)));
}

template<typename T>
GLM_API T floor(const T& value)
{
    static_cast<T>(std::floor(static_cast<double>(value)));
}

// 取小数部分
template <class T>
GLM_API T fract(const T& value)
{
    return value - floor(value);
}

template<typename T>
GLM_API T max(const T& x, const T& y)
{
    return x < y ? y : x;
}

template<typename T>
GLM_API T mid(const T& x, const T& y)
{
    return mix(x, y, constants<T>::half);
}

template<typename T>
GLM_API T min(const T& x, const T& y)
{
    return x < y ? x : y;
}

template<typename T, typename A>
GLM_API T mix(const T& x, const T& y, A a)
{
    return x + (y - x) * a;
}

// x - y * floor(x / y)
template<typename T>
GLM_API T mod(const T& x, const T& y)
{
    return x - y * floor(x / y);
}

template<typename T>
GLM_API T modf(const T& x, const T& y)
{
    return static_cast<T>(std::fmod(static_cast<float>(x), static_cast<float>(y)));
}

template<typename T>
GLM_API T pow(const T& x, const T& y)
{
    return static_cast<T>(std::pow(static_cast<double>(x), static_cast<double>(y)));
}

template<typename T>
GLM_API int round(const T& value)
{
    static_cast<T>(std::round(static_cast<double>(value)));
}

template<typename T>
GLM_API T sign(const T& value)
{
    return value < constants<T>::zero ? -constants<T>::one : constants<T>::one;
}

template<typename T>
GLM_API T sqrt(const T& value)
{
    return static_cast<T>(std::sqrt(static_cast<double>(value)));
}

//
// vec<N, T>
//

template<size_t N, typename T>
GLM_API vec<N, T> abs(const vec<N, T>& v)
{
    return compute<T, N, T>(abs<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> ceil(const vec<N, T>& v)
{
    return static_cast<T>(ceil<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> clamp(const vec<N, T>& v, T minVal, T maxVal)
{
    return compute<T, N, T>(clamp<T, T>, v, minVal, maxVal);
}

template<size_t N, typename T>
GLM_API vec<N, T> exp(const vec<N, T>& v)
{
    return compute<T, N, T>(exp<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> exp2(const vec<N, T>& v)
{
    return compute<T, N, T>(exp2<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> floor(const vec<N, T>& v)
{
    return compute<T, N, T>(floor<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> fract(const vec<N, T>& v)
{
    return compute<T, N, T>(fract<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> max(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>(max<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> mid(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>(mid<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> min(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>(min<T>, x, y);
}

template<size_t N, typename T, typename A>
GLM_API vec<N, T> mix(const vec<N, T>& x, const vec<N, T>& y, A a)
{
    return compute<T, N, T>(mix<T, A>, x, y, a);
}

template<size_t N, typename T>
GLM_API vec<N, T> mod(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>(mod<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> modf(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>(modf<T>, x, y);
}

template<size_t N, typename T>
GLM_API vec<N, T> pow(const vec<N, T>& x, const vec<N, T>& y)
{
    return compute<T, N, T>(pow<T>, x, y);
}

template<size_t N, typename T>
GLM_API int round(const vec<N, T>& v)
{
    return compute<T, N, T>(round<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> sign(const vec<N, T>& v)
{
    return compute<T, N, T>(sign<T>, v);
}

template<size_t N, typename T>
GLM_API vec<N, T> sqrt(const vec<N, T>& v)
{
    return compute<T, N, T>(sqrt<T>, v);
}

}// end namespace glm

#endif// GLM_FUNCTIONS_HPP_20211116114517
