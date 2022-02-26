/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 trigonometric.hpp

 2021-11-13 23:08:05

*/
#ifndef GLM_TRIGONOMETRIC_HPP_20211113230805
#define GLM_TRIGONOMETRIC_HPP_20211113230805

#include "constants.hpp"



namespace glm{

template<typename T>
GLM_API T radians(T value)
{
    return value * constants<T>::radians;
}

template<typename T>
GLM_API T degrees(T value)
{
    return value * constants<T>::inv_radians;
}

template<typename T>
GLM_API T sin(const T& value)
{
    return static_cast<T>(std::sin(static_cast<double>(value)));
}

template<typename T>
GLM_API T cos(const T& value)
{
    return static_cast<T>(std::cos(static_cast<double>(value)));
}

template<typename T>
GLM_API T tan(const T& value)
{
    return static_cast<T>(std::tan(static_cast<double>(value)));
}

// [-PI/2, PI/2]
template<typename T>
GLM_API T asin(const T& value)
{
    return static_cast<T>(std::asin(static_cast<double>(value)));
}

// [0, PI]
template<typename T>
GLM_API T acos(const T& value)
{
    return static_cast<T>(std::acos(static_cast<double>(value)));
}

// [-PI, PI]
template<typename T>
GLM_API T atan(const T& value)
{
    return static_cast<T>(std::atan(static_cast<double>(value)));
}

template<typename T>
GLM_API T atan(const T& x, const T& y)
{
    return static_cast<T>(std::atan2(static_cast<double>(x), static_cast<double>(y)));
}

}// end namespace glm

#endif// GLM_TRIGONOMETRIC_HPP_20211113230805
