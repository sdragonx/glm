/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 quaternion_functions.hpp

 2022-02-20 18:01:01

*/
#ifndef GLM_QUATERNION_FUNCTIONS_HPP_20220220180101
#define GLM_QUATERNION_FUNCTIONS_HPP_20220220180101

#include "../quat.hpp"



namespace glm {

//template<typename T>
//GLM_API vec<4, bool> isnan(const qua<T>& x)
//{
//    return vec<4, bool>(isnan(x.x), isnan(x.y), isnan(x.z), isnan(x.w));
//}
//
//template<typename T>
//GLM_API vec<4, bool> isinf(const qua<T>& x)
//{
//    return vec<4, bool>(isinf(x.x), isinf(x.y), isinf(x.z), isinf(x.w));
//}

template<typename T>
GLM_API vec<4, bool> equal(const qua<T>& x, const qua<T>& y)
{
    return vec<4, bool>(equal(x.x, y.x), equal(x.y, y.y), equal(x.z, y.z), equal(x.w, y.w));
}

template<typename T>
GLM_API vec<4, bool> notEqual(const qua<T>& x, const qua<T>& y)
{
    return vec<4, bool>(notEqual(x.x, y.x), notEqual(x.y, y.y), notEqual(x.z, y.z), notEqual(x.w, y.w));
}

// 两个四元数的球面线性插值。
// 插值是定向的，旋转是以恒定的速度进行的。
// 对于短路径球面线性插值，使用slerp函数。
// x    四元数
// y    四元数
// a    插值因子。插值的定义超出了范围[0,1]。
template<typename T>
GLM_API qua<T> mix(const qua<T>& x, const qua<T>& y, T a)
{
    T const cosTheta = dot(x, y);

    // Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
    if (cosTheta > static_cast<T>(1) - epsilon<T>()) {
        // Linear interpolation
        return qua<T>(
            mix(x.w, y.w, a),
            mix(x.x, y.x, a),
            mix(x.y, y.y, a),
            mix(x.z, y.z, a));
    }
    else {
        // Essential Mathematics, page 467
        T angle = acos(cosTheta);
        return (sin((static_cast<T>(1) - a) * angle) * x + sin(a * angle) * y) / sin(angle);
    }
}

// 两个四元数的线性插值。
// 插值是定向的。
// x    四元数
// y    四元数
// a    插值因子。插值定义在[0,1]范围内。
template<typename T>
GLM_API qua<T> lerp(const qua<T>& x, const qua<T>& y, T a)
{
    // Lerp is only defined in [0, 1]
    assert(a >= static_cast<T>(0));
    assert(a <= static_cast<T>(1));

    return x * (static_cast<T>(1) - a) + (y * a);
}

// 两个四元数的球面线性插值。
// 插补始终采用短路径，并且以恒定速度执行旋转。
// x    四元数
// y    四元数
// a    插值因子。插值的定义超出了范围[0,1]。
template<typename T>
GLM_API qua<T> slerp(const qua<T>& x, const qua<T>& y, T a)
{
    qua<T> z = y;

    T cosTheta = dot(x, y);

    // If cosTheta < 0, the interpolation will take the long way around the sphere.
    // To fix this, one quat must be negated.
    if (cosTheta < static_cast<T>(0)) {
        z = -y;
        cosTheta = -cosTheta;
    }

    // Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
    if (cosTheta > static_cast<T>(1) - epsilon<T>()) {
        // Linear interpolation
        return qua<T>(
            mix(x.w, z.w, a),
            mix(x.x, z.x, a),
            mix(x.y, z.y, a),
            mix(x.z, z.z, a));
    }
    else {
        // Essential Mathematics, page 467
        T angle = acos(cosTheta);
        return (sin((static_cast<T>(1) - a) * angle) * x + sin(a * angle) * z) / sin(angle);
    }
}

// 旋转轴上具有多个旋转的两个四元数的球面线性插值。
// 当自旋计数为正时，插值总是采用短路径，而当自旋计数为长路径时，插值总是采用长路径
// 当计数为负时。旋转以恒定速度进行。
// x    四元数
// y    四元数
// a    插值因子。插值的定义超出了范围[0,1]。
// k    额外旋转计数。如果值为负，则插值将位于“长”路径上。
template<typename T, typename S>
GLM_API qua<T> slerp(const qua<T>& x, const qua<T>& y, T a, S k)
{
    qua<T> z = y;

    T cosTheta = dot(x, y);

    // If cosTheta < 0, the interpolation will take the long way around the sphere.
    // To fix this, one quat must be negated.
    if (cosTheta < static_cast<T>(0)) {
        z = -y;
        cosTheta = -cosTheta;
    }

    // Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
    if (cosTheta > static_cast<T>(1) - epsilon<T>()) {
        // Linear interpolation
        return qua<T>(
            mix(x.w, z.w, a),
            mix(x.x, z.x, a),
            mix(x.y, z.y, a),
            mix(x.z, z.z, a));
    }
    else {
        // Graphics Gems III, page 96
        T angle = acos(cosTheta);
        T phi = angle + k * glm::pi<T>();
        return (sin(angle - a * phi)* x + sin(a * phi) * z) / sin(angle);
    }
}

// 返回四元数共轭
template<typename T>
GLM_API qua<T> conjugate(const qua<T>& q)
{
    return qua<T>(q.w, -q.x, -q.y, -q.z);
}

// 返回四元数的倒数。
template<typename T>
GLM_API qua<T> inverse(const qua<T>& q)
{
    return conjugate(q) / dot(q, q);
}

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

//
// functions
//

template<typename T>
GLM_API T roll(const qua<T>& q)
{
    return static_cast<T>(atan(static_cast<T>(2) * (q.x * q.y + q.w * q.z), q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z));
}

template<typename T>
GLM_API T pitch(const qua<T>& q)
{
    //return T(atan(T(2) * (q.y * q.z + q.w * q.x), q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z));
    T const y = static_cast<T>(2) * (q.y * q.z + q.w * q.x);
    T const x = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;

    if (all(equal(vec<2, T>(x, y), vec<2, T>(0), epsilon<T>()))) //avoid atan2(0,0) - handle singularity - Matiis
        return static_cast<T>(static_cast<T>(2) * atan(q.x, q.w));

    return static_cast<T>(atan(y, x));
}

template<typename T>
GLM_API T yaw(const qua<T>& q)
{
    return asin(clamp(static_cast<T>(-2) * (q.x * q.z - q.w * q.y), static_cast<T>(-1), static_cast<T>(1)));
}

template<typename T>
GLM_API vec<3, T> eulerAngles(const qua<T>& x)
{
    return vec<3, T>(pitch(x), yaw(x), roll(x));
}

template<typename T>
GLM_API mat<3, 3, T> mat3_cast(const qua<T>& q)
{
    mat<3, 3, T> Result(T(1));
    T qxx(q.x * q.x);
    T qyy(q.y * q.y);
    T qzz(q.z * q.z);
    T qxz(q.x * q.z);
    T qxy(q.x * q.y);
    T qyz(q.y * q.z);
    T qwx(q.w * q.x);
    T qwy(q.w * q.y);
    T qwz(q.w * q.z);

    Result[0][0] = T(1) - T(2) * (qyy + qzz);
    Result[0][1] = T(2) * (qxy + qwz);
    Result[0][2] = T(2) * (qxz - qwy);

    Result[1][0] = T(2) * (qxy - qwz);
    Result[1][1] = T(1) - T(2) * (qxx + qzz);
    Result[1][2] = T(2) * (qyz + qwx);

    Result[2][0] = T(2) * (qxz + qwy);
    Result[2][1] = T(2) * (qyz - qwx);
    Result[2][2] = T(1) - T(2) * (qxx + qyy);

    return Result;
}

template<typename T>
GLM_API mat<4, 4, T> mat4_cast(const qua<T>& q)
{
    return mat<4, 4, T>(mat3_cast(q));
}

template<typename T>
GLM_API qua<T> quat_cast(const mat<3, 3, T>& m)
{
    T fourXSquaredMinus1 = m[0][0] - m[1][1] - m[2][2];
    T fourYSquaredMinus1 = m[1][1] - m[0][0] - m[2][2];
    T fourZSquaredMinus1 = m[2][2] - m[0][0] - m[1][1];
    T fourWSquaredMinus1 = m[0][0] + m[1][1] + m[2][2];

    int biggestIndex = 0;
    T fourBiggestSquaredMinus1 = fourWSquaredMinus1;
    if (fourXSquaredMinus1 > fourBiggestSquaredMinus1) {
        fourBiggestSquaredMinus1 = fourXSquaredMinus1;
        biggestIndex = 1;
    }
    if (fourYSquaredMinus1 > fourBiggestSquaredMinus1) {
        fourBiggestSquaredMinus1 = fourYSquaredMinus1;
        biggestIndex = 2;
    }
    if (fourZSquaredMinus1 > fourBiggestSquaredMinus1) {
        fourBiggestSquaredMinus1 = fourZSquaredMinus1;
        biggestIndex = 3;
    }

    T biggestVal = sqrt(fourBiggestSquaredMinus1 + static_cast<T>(1)) * static_cast<T>(0.5);
    T mult = static_cast<T>(0.25) / biggestVal;

    switch (biggestIndex) {
    case 0:
        return qua<T>(biggestVal, (m[1][2] - m[2][1]) * mult, (m[2][0] - m[0][2]) * mult, (m[0][1] - m[1][0]) * mult);
    case 1:
        return qua<T>((m[1][2] - m[2][1]) * mult, biggestVal, (m[0][1] + m[1][0]) * mult, (m[2][0] + m[0][2]) * mult);
    case 2:
        return qua<T>((m[2][0] - m[0][2]) * mult, (m[0][1] + m[1][0]) * mult, biggestVal, (m[1][2] + m[2][1]) * mult);
    case 3:
        return qua<T>((m[0][1] - m[1][0]) * mult, (m[2][0] + m[0][2]) * mult, (m[1][2] + m[2][1]) * mult, biggestVal);
    default: // Silence a -Wswitch-default warning in GCC. Should never actually get here. Assert is just for sanity.
        //assert(false);
        throw("err");
        return qua<T>(1, 0, 0, 0);
    }
}

template<typename T>
GLM_API qua<T> quat_cast(const mat<4, 4, T>& m4)
{
    return quat_cast(mat<3, 3, T>(m4));
}

template<typename T>
GLM_API vec<4, bool> lessThan(const qua<T>& x, const qua<T>& y)
{
    vec<4, bool> Result;
    for (length_t i = 0; i < x.length(); ++i)
        Result[i] = x[i] < y[i];
    return Result;
}

template<typename T>
GLM_API vec<4, bool> lessThanEqual(const qua<T>& x, const qua<T>& y)
{
    vec<4, bool> Result;
    for (length_t i = 0; i < x.length(); ++i)
        Result[i] = x[i] <= y[i];
    return Result;
}

template<typename T>
GLM_API vec<4, bool> greaterThan(const qua<T>& x, const qua<T>& y)
{
    vec<4, bool> Result;
    for (length_t i = 0; i < x.length(); ++i)
        Result[i] = x[i] > y[i];
    return Result;
}

template<typename T>
GLM_API vec<4, bool> greaterThanEqual(const qua<T>& x, const qua<T>& y)
{
    vec<4, bool> Result;
    for (length_t i = 0; i < x.length(); ++i)
        Result[i] = x[i] >= y[i];
    return Result;
}

template<typename T>
GLM_API qua<T> quatLookAtRH(const vec<3, T>& direction, const vec<3, T>& up)
{
    mat<3, 3, T> Result;

    Result[2] = -direction;
    const vec<3, T>& Right = cross(up, Result[2]);
    Result[0] = Right * inversesqrt(max(static_cast<T>(0.00001), dot(Right, Right)));
    Result[1] = cross(Result[2], Result[0]);

    return quat_cast(Result);
}

template<typename T>
GLM_API qua<T> quatLookAtLH(const vec<3, T>& direction, const vec<3, T>& up)
{
    mat<3, 3, T> Result;

    Result[2] = direction;
    const vec<3, T>& Right = cross(up, Result[2]);
    Result[0] = Right * inversesqrt(max(static_cast<T>(0.00001), dot(Right, Right)));
    Result[1] = cross(Result[2], Result[0]);

    return quat_cast(Result);
}

template<typename T>
GLM_API qua<T> quatLookAt(const vec<3, T>& direction, const vec<3, T>& up)
{
    return quatLookAtRH(direction, up);
}

}// end namespace glm

#endif// GLM_QUATERNION_FUNCTIONS_HPP_20220220180101
