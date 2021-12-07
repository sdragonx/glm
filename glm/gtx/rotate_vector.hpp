/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 rotate_vector.hpp

 2021-11-15 23:21:06

*/
#ifndef GLM_ROTATE_VECTOR_HPP_20211115232106
#define GLM_ROTATE_VECTOR_HPP_20211115232106

#include "../vec.hpp"

namespace cgl{
namespace glm{

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
    return rotate(angle, axis) * vec<4, T>(v, constant<T>::one);
}

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

}// end namespace glm
}// end namespace cgl

#endif// GLM_ROTATE_VECTOR_HPP_20211115232106
