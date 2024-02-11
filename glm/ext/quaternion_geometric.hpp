/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 quaternion_geometric.hpp

 2024-02-10 22:19:26

*/
#ifndef GLM_QUATERNION_GEOMETRIC_HPP_20240210221926
#define GLM_QUATERNION_GEOMETRIC_HPP_20240210221926

#include "../quat.hpp"



namespace glm {

// Returns dot product of q1 and q2, i.e., q1[0] * q2[0] + q1[1] * q2[1] + ...
template<typename T>
GLM_API T dot(const qua<T>& x, const qua<T>& y)
{
    vec<4, T> tmp(x.w * y.w, x.x * y.x, x.y * y.y, x.z * y.z);
    return (tmp.x + tmp.y) + (tmp.z + tmp.w);
}

// Returns the norm of a quaternions
template<typename T>
GLM_API T length(const qua<T>& q)
{
    return glm::sqrt(dot(q, q));
}

// Returns the normalized quaternion.
template<typename T>
GLM_API qua<T> normalize(const qua<T>& q)
{
    T n = length(q);
    if (n <= static_cast<T>(0)) { // Problem
        return qua<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
    }

    T invN = static_cast<T>(1) / n;
    return qua<T>(q.w * invN, q.x * invN, q.y * invN, q.z * invN);
}

// Compute a cross product.
template<typename T>
GLM_API qua<T> cross(const qua<T>& q1, const qua<T>& q2)
{
    return qua<T>(
        q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
        q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
        q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
        q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x);
}

}// end namespace glm

#endif// GLM_QUATERNION_GEOMETRIC_HPP_20240210221926
