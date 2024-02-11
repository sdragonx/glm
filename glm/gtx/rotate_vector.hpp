/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 rotate_vector.hpp

 2021-11-15 23:21:06

*/
#ifndef GLM_ROTATE_VECTOR_HPP_20211115232106
#define GLM_ROTATE_VECTOR_HPP_20211115232106

#include "../vector.hpp"



namespace glm {

//
// vec<3, T> slerp(vec<3, T> x, vec<3, T> y, T a)
//

template<typename T>
vec<3, T> slerp(const vec<3, T>& x, const vec<3, T>& y, const T& a)
{
    // get cosine of angle between vectors (-1 -> 1)
    T cosAlpha = dot(x, y);
    // get angle (0 -> pi)
    T alpha = acos(cosalpha);
    // get sine of angle between vectors (0 -> 1)
    T sinAlpha = sin(alpha);
    // this breaks down when sinAlpha = 0, i.e. alpha = 0 or pi
    T t1 = sin((static_cast<T>(1) - a) * alpha) / sinAlpha;
    T t2 = sin(a * alpha) / sinAlpha;

    // interpolate src vectors
    return x * t1 + y * t2;
}

//
// vec<2, T> rotate( vec<2, T>, angle )
//

template<typename T>
vec<2, T> rotate( const vec<2, T>& v, T angle )
{
    T sine = sin(angle);
    T cosine = cos(angle);
    return vec<2, T>(
        v.x * cosine - v.y * sine,
        v.y * cosine + v.x * sine
    );
}

//
// vec<3, T> rotate( ... )
//

template<typename T>
vec<3, T> rotate( const vec<3, T>& v, T angle, const vec<3, T>& axis )
{
    return rotate(angle, axis) * vec<4, T>(v, constants<T>::one);
}

/* ÈÆ x ÖáÐý×ª
 */
template<typename T>
vec<3, T> rotateX( const vec<3, T>& v, T angle )
{
    T cosine = cos(angle);
    T sine = sin(angle);

    return vec<3, T>(
        v.x,
        v.y * cosine - v.z * sine,
        v.y * sine + v.z * cosine);
}

/* ÈÆ y ÖáÐý×ª
 */
template<typename T>
vec<3, T> rotateY( const vec<3, T>& v, T angle )
{
    T cosine = cos(angle);
    T sine = sin(angle);

    return vec<3, T>(
        v.x * cosine + v.z * sine,
        v.y,
        -v.x * sine + v.z * cosine);
}

/* ÈÆ z ÖáÐý×ª
 */
template<typename T>
vec<3, T> rotateZ( const vec<3, T>& v, T angle )
{
    T cosine = cos(angle);
    T sine = sin(angle);

    return vec<3, T>(
        v.x * cosine - v.y * sine,
        v.x * sine + v.y * cosine,
        v.z);
}

//
// vec<4, T> rotate( ... )
//

template<typename T>
vec<4, T> rotate( const vec<4, T>& v, T angle, const vec<3, T>& axis )
{
    return rotate(angle, axis) * v;
}

template<typename T>
vec<4, T> rotateX( const vec<4, T>& v, T angle )
{
    T cosine = cos(angle);
    T sine = sin(angle);

    return vec<4, T>(
        v.x,
        v.y * cosine - v.z * sine,
        v.y * sine + v.z * cosine,
        v.w);
}

template<typename T>
vec<4, T> rotateY( const vec<4, T>& v, T angle )
{
    T cosine = cos(angle);
    T sine = sin(angle);

    return vec<4, T>(
        v.x * cosine + v.z * sine,
        v.y,
        -v.x * sine + v.z * cosine,
        v.w);
}

template<typename T>
vec<4, T> rotateZ( const vec<4, T>& v, T angle )
{
    T cosine = cos(angle);
    T sine = sin(angle);

    return vec<4, T>(
        v.x * cosine - v.y * sine,
        v.x * sine + v.y * cosine,
        v.z,
        v.w);
}

//
// mat<4, 4, T> orientation(vec<3, T> normal, vec<3, T> up)
//

template<typename T>
mat<4, 4, T> orientation(const vec<3, T>& normal, const vec<3, T>& up)
{
    if(all(equal(normal, up, epsilon<T>())))
        return mat<4, 4, T>(static_cast<T>(1));

    vec<3, T> rotationAxis = cross(up, normal);
    T angle = acos(dot(normal, up));

    return rotate(angle, rotationAxis);
}

}// end namespace glm

#endif// GLM_ROTATE_VECTOR_HPP_20211115232106
