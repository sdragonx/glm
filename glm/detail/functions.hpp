/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 functions.hpp

 2021-11-16 11:45:17

 roundEven
 matrixCompMult

*/
#ifndef GLM_FUNCTIONS_HPP_20211116114517
#define GLM_FUNCTIONS_HPP_20211116114517

#include "constants.hpp"

#ifdef min
    #undef min
#endif

#ifdef max
    #undef max
#endif



namespace glm {
	
template<typename T>
GLM_API T min(const T& x, const T& y)
{
    return x < y ? x : y;
}

template<typename T>
GLM_API T max(const T& x, const T& y)
{
    return x < y ? y : x;
}

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
    return static_cast<T>(std::exp2(static_cast<double>(value)));
}

template<typename T>
GLM_API T floor(const T& value)
{
    return static_cast<T>(std::floor(static_cast<double>(value)));
}

// 取小数部分
template <class T>
GLM_API T fract(const T& value)
{
    return value - floor(value);
}

template<typename T>
GLM_API T mix(const T& x, const T& y, const T& a)
{
    return x + (y - x) * a;
}

template<typename T, typename A>
GLM_API T mix(const T& x, const T& y, const A& a)
{
    return x + (y - x) * static_cast<T>(a);
}

template<typename T>
GLM_API T mid(const T& x, const T& y)
{
    return mix(x, y, constants<T>::half);
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
GLM_API T round(const T& value)
{
    return value + (value < T(0) ? T(-0.5) : (0.5));
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

template<typename T>
GLM_API T step(const T& edge, const T& x)
{
    return mix(static_cast<T>(1), static_cast<T>(0), x < edge);
}

template<typename T>
GLM_API T smoothstep(const T& edge0, const T& edge1, const T& x)
{
    T const tmp(clamp((x - edge0) / (edge1 - edge0), T(0), T(1)));
    return tmp * tmp * (T(3) - T(2) * tmp);
}

}// end namespace glm

#endif// GLM_FUNCTIONS_HPP_20211116114517
