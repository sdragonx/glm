/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 matrix_transform.hpp

 2021-11-13 21:44:55

*/
#ifndef MATRIX_TRANSFORM_HPP_20211113214455
#define MATRIX_TRANSFORM_HPP_20211113214455

#include "../vec.hpp"
#include "../mat.hpp"
#include "../detail/type_traits.hpp"
#include "../trigonometric.hpp"

namespace cgl{
namespace glm{

//
// class matrix_transform
//

template<typename T>
class matrix_transform : public constants<T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    using constants<T>::zero;
    using constants<T>::half;
    using constants<T>::one;
    using constants<T>::two;

public:
    static GLM_API mat<4, 4, T> translate(const vec<3, T>& v)
    {
        return mat<4, 4, T>(
            one,  zero, zero, zero,
            zero, one,  zero, zero,
            zero, zero, one,  zero,
            v.x,  v.y,  v.z,  one);
    }
    
    static GLM_API mat<4, 4, T> rotate(T angle, const vec<3, T>& axis)
    {
        T cosine = cos(angle);
        T sine = sin(angle);

        vec<3, T> u = normalize(axis);
        vec<3, T> t = u * (one - cosine);

        return mat<4, 4, T>(
            cosine + (u.x * t.x),       (u.y * t.x) + (u.z * sine), (u.z * t.x) - (u.y * sine), zero,
            (u.x * t.y) - (u.z * sine), cosine + (u.y * t.y),       (u.z * t.y) + (u.x * sine), zero,
            (u.x * t.z) + (u.y * sine), (u.y * t.z) - (u.x * sine), cosine + (u.z * t.z),       zero,
            zero,                       zero,                       zero,                       one);
    }

    static GLM_API mat<4, 4, T> scale(const vec<3, T>& v)
    {
        return mat<4, 4, T>(
            v.x, zero, zero, zero,
            zero, v.y, zero, zero,
            zero, zero, v.z, zero,
            zero, zero, zero, one);
    }

    // ÊÓ¿Ú¾ØÕó
    static GLM_API mat<4, 4, T> viewport(T x, T y, T w, T h)
    {
        // identity();
        // translate(x + w * 0.5f, y + h * 0.5f, zero);
        // scale(w * 0.5, h * 0.5, 1.0f);

        w *= half;
        h *= half;
        return mat<4, 4, T>(
            w,     zero,  zero, zero,
            zero,  h,     zero, zero,
            zero,  zero,  zero, zero, // z 1.0 ?
            x + w, y + h, zero, one);
    }

    static GLM_API mat<4, 4, T> frustum(T left, T right, T bottom, T top, T zNear, T zFar)
    {
        const T two = T(2);
        T w = right - left;
        T h = top - bottom;
        T d = zFar - zNear;
        return mat<4, 4, T>(
            (two * zNear) / w,   zero,                 zero,                      zero,
            zero,                (two * zNear) / h,    zero,                      zero,
            (right + left) / w, -(zFar + zNear) / d,   (top + bottom) / h,       -one,
            zero,                zero,                -(two * zFar * zNear) / d,  zero);
    }

    static GLM_API mat<4, 4, T> perspective(T fovY, T aspect, T zNear, T zFar)
    {
        #if 0
        T h = tan(fovY * half) * zNear;
        T w = h * aspect;
        return frustum(-w, w, -h, h, zNear, zFar);
        #else
        const T tanHalfFovy = tan(fovY * half);
        mat<4, 4, T> m(zero);
        m[0][0] = one / (aspect * tanHalfFovy);
        m[1][1] = one / (tanHalfFovy);
        m[2][2] = zFar / (zNear - zFar);
        m[2][3] = -one;
        m[3][2] = -(two * zFar + zNear) / (zFar - zNear);
        return m;
        #endif
    }

    static GLM_API mat<4, 4, T> ortho(T left, T right, T bottom, T top, T zNear, T zFar)
    {
        T w = right - left;
        T h = top - bottom;
        T d = zFar - zNear;
        return mat<4, 4, T>(
            two / w,             zero,                 zero,               zero,
            zero,                two / h,              zero,               zero,
            zero,                zero,                -two / d,            zero,
            -(right + left) / w, -(top + bottom) / h, -(zFar + zNear) / d, one);
    }

    static GLM_API mat<4, 4, T> ortho(T left, T right, T bottom, T top)
    {
        T w = right - left;
        T h = top - bottom;
        return mat<4, 4, T>(
            two / w, zero, zero, zero,
            zero, two / h, zero, zero,
            zero, zero, -one, zero,
            -(right + left) / w, -(top + bottom) / h, zero, one);
    }

    static GLM_API mat<4, 4, T> lookAtLH(const vec<3, T>& eye, const vec<3, T>& center, const vec<3, T>& up)
    {
        vec<3, T> f(normalize(center - eye));   // forward
        vec<3, T> s(normalize(cross(f, up)));   // side
        vec<3, T> u(cross(s, f));               // up

        return mat<4, 4, T>(
            s.x, s.y, s.z, zero,
            u.x, u.y, u.z, zero,
            f.x, f.y, f.z, zero,
            -dot(s, eye), -dot(u, eye), -dot(f, eye), one);
    }

    static GLM_API mat<4, 4, T> lookAtRH(const vec<3, T>& eye, const vec<3, T>& center, const vec<3, T>& up)
    {
        vec<3, T> f(normalize(center - eye));   // forward
        vec<3, T> s(normalize(cross(f, up)));   // side
        vec<3, T> u(cross(s, f));               // up

        return mat<4, 4, T>(
            s.x, s.y, s.z, zero,
            u.x, u.y, u.z, zero,
            -f.x, -f.y, -f.z, zero,
            -dot(s, eye), -dot(u, eye), dot(f, eye), one);
    }
};

//
// identity
//

template<typename genT>
GLM_API genT identity()
{
    return type_traits<genT, typename genT::value_type>::identity();
}

//
// translate
//

template<typename T>
GLM_API mat<4, 4, T> translate(const vec<3, T>& v)
{
    return matrix_transform<T>::translate(v);
}

template<typename T>
GLM_API mat<4, 4, T> translate(const mat<4, 4, T>& m, const vec<3, T>& v)
{
    return m * translate<T>(v);
}

//
// rotate
//

template<typename T>
GLM_API mat<4, 4, T> rotate(T angle, const vec<3, T>& axis)
{
    return matrix_transform<T>::rotate(angle, axis);
}

template<typename T>
GLM_API mat<4, 4, T> rotate(const mat<4, 4, T>& m, T angle, const vec<3, T>& axis)
{
    return m * matrix_transform<T>::rotate(angle, axis);
}

//
// scale
//

template<typename T>
GLM_API mat<4, 4, T> scale(const vec<3, T>& v)
{
    return matrix_transform<T>::scale(v);
}

template<typename T>
GLM_API mat<4, 4, T> scale(const mat<4, 4, T>& m, const vec<3, T>& v)
{
    // glm
    #if 1
    mat<4, 4, T> product;
    product[0] = m[0] * v[0];
    product[1] = m[1] * v[1];
    product[2] = m[2] * v[2];
    product[3] = m[3];
    return product;
    #else
    return m * matrix_transform<T>::scale(v);
    #endif
}

//
// frustum
//

template<typename T>
GLM_API mat<4, 4, T> frustum(T left, T right, T bottom, T top, T zNear, T zFar)
{
    return matrix_transform<T>::frustum(left, right, bottom, top, zNear, zFar);
}

//
// perspective
//

template<typename T>
GLM_API mat<4, 4, T> perspective(T fovY, T aspectRatio, T zNear, T zFar)
{
    return matrix_transform<T>::perspective(fovY, aspectRatio, zNear, zFar);
}

//
// ortho
//

template<typename T>
GLM_API mat<4, 4, T> ortho(T left, T right, T bottom, T top)
{
    return matrix_transform<T>::ortho(left, right, bottom, top);
}

template<typename T>
GLM_API mat<4, 4, T> ortho(T left, T right, T bottom, T top, T zNear, T zFar)
{
    return matrix_transform<T>::ortho(left, right, bottom, top, zNear, zFar);
}

//
// lookAt
//

template<typename T>
GLM_API mat<4, 4, T> lookAtLH(const vec<3, T>& eye, const vec<3, T>& center, const vec<3, T>& up)
{
    return matrix_transform<T>::lookAtLH(eye, center, up);
}

template<typename T>
GLM_API mat<4, 4, T> lookAtRH(const vec<3, T>& eye, const vec<3, T>& center, const vec<3, T>& up)
{
    return matrix_transform<T>::lookAtRH(eye, center, up);
}

template<typename T>
GLM_API mat<4, 4, T> lookAt(const vec<3, T>& eye, const vec<3, T>& center, const vec<3, T>& up)
{
    return lookAtRH<T>(eye, center, up);
}

}// end namespace glm
}// end namespace cgl

#endif// MATRIX_TRANSFORM_HPP_20211113214455
