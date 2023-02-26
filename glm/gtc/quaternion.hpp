/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 quaternion.hpp

 2022-02-20 01:11:08

*/
#ifndef GLM_QUATERNION_HPP_20220220011108
#define GLM_QUATERNION_HPP_20220220011108

#include "../quat.hpp"
#include "quaternion_functions.hpp"
#include "quaternion_trigonometric.hpp"



namespace glm {

/* 从两个归一化轴创建四元数
 * u    第一个归一化的轴
 * v    第二个归一化的轴
 * 
 * http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
 */
template<typename T>
GLM_API qua<T>::qua(const vec<3, T>& u, const vec<3, T>& v)
{
    T norm_u_norm_v = sqrt(dot(u, u) * dot(v, v));
    T real_part = norm_u_norm_v + dot(u, v);
    vec<3, T> t;

    if (real_part < static_cast<T>(1.e-6f) * norm_u_norm_v) {
        /* If u and v are exactly opposite, rotate 180 degrees
         * around an arbitrary orthogonal axis. Axis normalisation
         * can happen later, when we normalise the quaternion.
         */
        real_part = static_cast<T>(0);
        t = abs(u.x) > abs(u.z) ? vec<3, T>(-u.y, u.x, static_cast<T>(0)) : vec<3, T>(static_cast<T>(0), -u.z, u.y);
    }
    else {
        // Otherwise, build quaternion the standard way.
        t = cross(u, v);
    }

    *this = normalize(qua(real_part, t.x, t.y, t.z));
}

template<typename T>
GLM_API qua<T>::qua(const mat<3, 3, T>& m)
{
    *this = quat_cast(m);
}

template<typename T>
GLM_API qua<T>::qua(const mat<4, 4, T>& m)
{
    *this = quat_cast(m);
}

template<typename T>
GLM_API qua<T>::operator mat<3, 3, T>() const
{
    return mat3_cast(*this);
}

template<typename T>
GLM_API qua<T>::operator mat<4, 4, T>() const
{
    return mat4_cast(*this);
}

//
// functions
//

template<typename T>
GLM_API qua<T> quat_mul(const qua<T>& q, T scalar)
{
    return qua<T>(q.w * scalar, q.x * scalar, q.y * scalar, q.z * scalar);
}

template<typename T>
GLM_API qua<T> quat_div(const qua<T>& q, T scalar)
{
    return qua<T>(q.w / scalar, q.x / scalar, q.y / scalar, q.z / scalar);
}

template<typename T>
GLM_API qua<T> quat_add(const qua<T>& q, const qua<T>& p)
{
    return qua<T>(q.w + p.w, q.x + p.x, q.y + p.y, q.z + p.z);
}

template<typename T>
GLM_API qua<T> quat_sub(const qua<T>& q, const qua<T>& p)
{
    return qua<T>(q.w - p.w, q.x - p.x, q.y - p.y, q.z - p.z);
}

template<typename T>
GLM_API qua<T> quat_mul(const qua<T>& q, const qua<T>& p)
{
    T w = q.w * p.w - q.x * p.x - q.y * p.y - q.z * p.z;
    T x = q.w * p.x + q.x * p.w + q.y * p.z - q.z * p.y;
    T y = q.w * p.y + q.y * p.w + q.z * p.x - q.x * p.z;
    T z = q.w * p.z + q.z * p.w + q.x * p.y - q.y * p.x;
    return qua<T>(w, x, y, z);
}

template<typename T>
GLM_API vec<3, T> quat_mul_vec3(const qua<T>& q, const vec<3, T>& v)
{
    vec<3, T> const qv(q.x, q.y, q.z);
    vec<3, T> const uv(glm::cross(qv, v));
    vec<3, T> const uuv(glm::cross(qv, uv));

    return v + ((uv * q.w) + uuv) * static_cast<T>(2);
}

template<typename T>
GLM_API vec<4, T> quat_mul_vec4(const qua<T>& q, const vec<4, T>& v)
{
    return vec<4, T>(quat_mul_vec3(q, vec<3, T>(v)), v.w);
};

//
// quat operation scalar
//

template<typename T>
GLM_API qua<T> operator+(const qua<T>& q, T scalar)
{
    return qua<T>(q.w + scalar, q.x + scalar, q.y + scalar, q.z + scalar);
}

template<typename T>
GLM_API qua<T> operator-(const qua<T>& q, T scalar)
{
    return qua<T>(q.w - scalar, q.x - scalar, q.y - scalar, q.z - scalar);
}

template<typename T>
GLM_API qua<T> operator*(const qua<T>& q, T scalar)
{
    return qua<T>(q.w * scalar, q.x * scalar, q.y * scalar, q.z * scalar);
}

template<typename T>
GLM_API qua<T> operator/(const qua<T>& q, T scalar)
{
    return qua<T>(q.w / scalar, q.x / scalar, q.y / scalar, q.z / scalar);
}

//
// scalar operation quat
//

template<typename T>
GLM_API qua<T> operator+(T scalar, const qua<T>& q)
{
    return qua<T>(scalar + q.w, scalar + q.x, scalar + q.y, scalar + q.z);
}

template<typename T>
GLM_API qua<T> operator-(T scalar, const qua<T>& q)
{
    return qua<T>(scalar - q.w, scalar - q.x, scalar - q.y, scalar - q.z);
}

template<typename T>
GLM_API qua<T> operator*(T scalar, const qua<T>& q)
{
    return qua<T>(scalar * q.w, scalar * q.x, scalar * q.y, scalar * q.z);
}

//
// quat operation quat
//

template<typename T>
GLM_API qua<T> operator+(const qua<T>& q, const qua<T>& p)
{
    return quat_add(q, p);
}

template<typename T>
GLM_API qua<T> operator-(const qua<T>& q, const qua<T>& p)
{
    return quat_sub(q, p);
}

template<typename T>
GLM_API qua<T> operator*(const qua<T>& q, const qua<T>& p)
{
    return quat_mul(q, p);
}

// vec3 = quat * vec3
template<typename T>
GLM_API vec<3, T> operator*(const qua<T>& q, const vec<3, T>& v)
{
    return quat_mul_vec3(q, v);
}

// vec3 = vec3 * quat
template<typename T>
GLM_API vec<3, T> operator*(const vec<3, T>& v, const qua<T>& q)
{
    return quat_mul_vec3(inverse(q), v);
}

// vec4 = quat * vec4
template<typename T>
GLM_API vec<4, T> operator*(const qua<T>& q, const vec<4, T>& v)
{
    return quat_mul_vec4(q, v);
}

// vec4 = vec4 * quat
template<typename T>
GLM_API vec<4, T> operator*(const vec<4, T>& v, const qua<T>& q)
{
    return quat_mul_vec4(inverse(q), v);
}

// operator ==
template<typename T>
GLM_API bool operator==(const qua<T>& q1, const qua<T>& q2)
{
    return equal(q1.w, q2.w) && equal(q1.x, q2.x) && equal(q1.y, q2.y) && equal(q1.z, q2.z);
}

// operator !-
template<typename T>
GLM_API bool operator!=(const qua<T>& q1, const qua<T>& q2)
{
    return notEqual(q1.w, q2.w) && notEqual(q1.x, q2.x) && notEqual(q1.y, q2.y) && notEqual(q1.z, q2.z);
}


}// end namespace glm

#endif// GLM_QUATERNION_HPP_20220220011108
