/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 quaternion_trigonometric.hpp

 2022-02-20 17:55:03

*/
#ifndef GLM_QUATERNION_TRIGONOMETRIC_HPP_20220220175503
#define GLM_QUATERNION_TRIGONOMETRIC_HPP_20220220175503

#include "../quat.hpp"



namespace glm {

template<typename T>
GLM_API T angle(const qua<T>& x)
{
    if (abs(x.w) > cos_one_over_two<T>()) {
        return asin(sqrt(x.x * x.x + x.y * x.y + x.z * x.z)) * static_cast<T>(2);
    }

    return acos(x.w) * static_cast<T>(2);
}

template<typename T>
GLM_API vec<3, T> axis(const qua<T>& x)
{
    T const n = static_cast<T>(1) - x.w * x.w;
    if (n <= static_cast<T>(0))
        return vec<3, T>(0, 0, 1);
    T const invN = static_cast<T>(1) / sqrt(n);
    return vec<3, T>(x.x * invN, x.y * invN, x.z * invN);
}

template<typename T>
GLM_API qua<T> angleAxis(T const& angle, vec<3, T> const& v)
{
    T const a(angle);
    T const s = glm::sin(a * static_cast<T>(0.5));

    return qua<T>(glm::cos(a * static_cast<T>(0.5)), v * s);
}

}// end namespace glm

#endif// GLM_QUATERNION_TRIGONOMETRIC_HPP_20220220175503
