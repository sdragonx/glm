/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 normal.hpp

 2021-12-31 17:19:36

*/
#ifndef GLM_NORMAL_HPP_20211231171936
#define GLM_NORMAL_HPP_20211231171936

#include "../vector.hpp"

namespace glm {

//
// vec3 triangleNormal( in vec3, in vec3, in vec3 )
//

template<typename T>
inline vec<3, T> triangleNormal(const vec<3, T>& a, const vec<3, T>& b, const vec<3, T>& c)
{
    //return normalize(cross(a - b, a - c));// glm
    return normalize(cross(b - a, c - a));
}

}// end namespace glm

#endif// GLM_NORMAL_HPP_20211231171936
