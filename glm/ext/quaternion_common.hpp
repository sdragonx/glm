/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 quaternion_common.hpp

 2024-02-10 22:15:33

*/
#ifndef GLM_QUATERNION_COMMON_HPP_20240210221533
#define GLM_QUATERNION_COMMON_HPP_20240210221533

#include "../quat.hpp"



namespace glm {

/* 两个四元数的球面线性插值。
 * 插值是定向的，旋转是以恒定的速度进行的。
 * 对于短路径球面线性插值，使用slerp函数。
 * x    四元数
 * y    四元数
 * a    插值因子。插值的定义超出了范围[0,1]。
 */
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

/* 两个四元数的线性插值。
 * 插值是定向的。
 * x    四元数
 * y    四元数
 * a    插值因子。插值定义在[0,1]范围内。
 */
template<typename T>
GLM_API qua<T> lerp(const qua<T>& x, const qua<T>& y, T a)
{
    // Lerp is only defined in [0, 1]
    assert(a >= static_cast<T>(0));
    assert(a <= static_cast<T>(1));

    return x * (static_cast<T>(1) - a) + (y * a);
}

/* 两个四元数的球面线性插值。
 * 插补始终采用短路径，并且以恒定速度执行旋转。
 * x    四元数
 * y    四元数
 * a    插值因子。插值的定义超出了范围[0,1]。
 */
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

/* 旋转轴上具有多个旋转的两个四元数的球面线性插值。
 * 当自旋计数为正时，插值总是采用短路径，而当自旋计数为长路径时，插值总是采用长路径
 * 当计数为负时。旋转以恒定速度进行。
 * x    四元数
 * y    四元数
 * a    插值因子。插值的定义超出了范围[0,1]。
 * k    额外旋转计数。如果值为负，则插值将位于“长”路径上。
 */
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

/* 返回四元数共轭
 */
template<typename T>
GLM_API qua<T> conjugate(const qua<T>& q)
{
    return qua<T>(q.w, -q.x, -q.y, -q.z);
}

/* 返回四元数的倒数。
 */
template<typename T>
GLM_API qua<T> inverse(const qua<T>& q)
{
    return conjugate(q) / dot(q, q);
}

template<typename T>
GLM_API vec<4, bool> isnan(const qua<T>& x)
{
    return vec<4, bool>(isnan(x.x), isnan(x.y), isnan(x.z), isnan(x.w));
}

template<typename T>
GLM_API vec<4, bool> isinf(const qua<T>& x)
{
    return vec<4, bool>(isinf(x.x), isinf(x.y), isinf(x.z), isinf(x.w));
}

}// end namespace glm

#endif// GLM_QUATERNION_COMMON_HPP_20240210221533
