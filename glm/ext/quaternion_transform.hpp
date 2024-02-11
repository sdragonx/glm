/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 quaternion_transform.hpp

 2024-02-10 22:25:33

*/
#ifndef GLM_QUATERNION_TRANSFORM_HPP_20240210222533
#define GLM_QUATERNION_TRANSFORM_HPP_20240210222533

#include "../quat.hpp"



namespace glm {

/* Rotates a quaternion from a vector of 3 components axis and an angle.
 *
 * q        Source orientation
 * angle    Angle expressed in radians.
 * axis     Axis of the rotation
 */
template<typename T>
GLM_API qua<T> rotate(const qua<T>& q, const T& angle, const vec<3, T>& v)
{
    vec<3, T> axis = v;

    // Axis of rotation must be normalised
    T d = glm::length(axis);
    if (abs(d - static_cast<T>(1)) > static_cast<T>(0.001)) {
        d = static_cast<T>(1) / d;
        axis.x *= d;
        axis.y *= d;
        axis.z *= d;
    }

    const T a = angle * static_cast<T>(0.5);
    const T sine = sin(a);
    const T cosine = cos(a);

    return q * qua<T>(cosine, axis.x * sine, axis.y * sine, axis.z * sine);
}

}// end namespace glm

#endif// GLM_QUATERNION_TRANSFORM_HPP_20240210222533
