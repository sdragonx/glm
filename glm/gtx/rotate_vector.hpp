/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 rotate_vector.hpp

 2021-11-15 23:21:06

*/
#ifndef ROTATE_VECTOR_HPP_20211115232106
#define ROTATE_VECTOR_HPP_20211115232106

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



}// end namespace glm
}// end namespace cgl

#endif// ROTATE_VECTOR_HPP_20211115232106
