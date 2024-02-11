/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 quaternion_common.hpp

 2024-02-10 22:15:33

*/
#ifndef GLM_QUATERNION_COMMON_HPP_20240210221533
#define GLM_QUATERNION_COMMON_HPP_20240210221533

#include "../quat.hpp"



namespace glm {

/* ������Ԫ�����������Բ�ֵ��
 * ��ֵ�Ƕ���ģ���ת���Ժ㶨���ٶȽ��еġ�
 * ���ڶ�·���������Բ�ֵ��ʹ��slerp������
 * x    ��Ԫ��
 * y    ��Ԫ��
 * a    ��ֵ���ӡ���ֵ�Ķ��峬���˷�Χ[0,1]��
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

/* ������Ԫ�������Բ�ֵ��
 * ��ֵ�Ƕ���ġ�
 * x    ��Ԫ��
 * y    ��Ԫ��
 * a    ��ֵ���ӡ���ֵ������[0,1]��Χ�ڡ�
 */
template<typename T>
GLM_API qua<T> lerp(const qua<T>& x, const qua<T>& y, T a)
{
    // Lerp is only defined in [0, 1]
    assert(a >= static_cast<T>(0));
    assert(a <= static_cast<T>(1));

    return x * (static_cast<T>(1) - a) + (y * a);
}

/* ������Ԫ�����������Բ�ֵ��
 * �岹ʼ�ղ��ö�·���������Ժ㶨�ٶ�ִ����ת��
 * x    ��Ԫ��
 * y    ��Ԫ��
 * a    ��ֵ���ӡ���ֵ�Ķ��峬���˷�Χ[0,1]��
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

/* ��ת���Ͼ��ж����ת��������Ԫ�����������Բ�ֵ��
 * ����������Ϊ��ʱ����ֵ���ǲ��ö�·����������������Ϊ��·��ʱ����ֵ���ǲ��ó�·��
 * ������Ϊ��ʱ����ת�Ժ㶨�ٶȽ��С�
 * x    ��Ԫ��
 * y    ��Ԫ��
 * a    ��ֵ���ӡ���ֵ�Ķ��峬���˷�Χ[0,1]��
 * k    ������ת���������ֵΪ�������ֵ��λ�ڡ�����·���ϡ�
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

/* ������Ԫ������
 */
template<typename T>
GLM_API qua<T> conjugate(const qua<T>& q)
{
    return qua<T>(q.w, -q.x, -q.y, -q.z);
}

/* ������Ԫ���ĵ�����
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
