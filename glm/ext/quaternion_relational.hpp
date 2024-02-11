/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 quaternion_relational.hpp

 2024-02-10 22:08:34

*/
#ifndef GLM_QUATERNION_RELATIONAL_HPP_20240210220834
#define GLM_QUATERNION_RELATIONAL_HPP_20240210220834

#include "../quat.hpp"



namespace glm {

template<typename T>
GLM_API vec<4, bool> equal(const qua<T>& x, const qua<T>& y)
{
    return vec<4, bool>(equal(x.x, y.x), equal(x.y, y.y), equal(x.z, y.z), equal(x.w, y.w));
}

template<typename T>
GLM_API vec<4, bool> equal(const qua<T>& x, const qua<T>& y, T epsilon)
{
    vec<4, T> v(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w);
    return lessThan(abs(v), vec<4, T>(epsilon));
}

template<typename T>
GLM_API vec<4, bool> notEqual(const qua<T>& x, const qua<T>& y)
{
    return vec<4, bool>(notEqual(x.x, y.x), notEqual(x.y, y.y), notEqual(x.z, y.z), notEqual(x.w, y.w));
}

template<typename T>
GLM_API vec<4, bool> notEqual(const qua<T>& x, const qua<T>& y, T epsilon)
{
    vec<4, T> v(x.x - y.x, x.y - y.y, x.z - y.z, x.w - y.w);
    return greaterThanEqual(abs(v), vec<4, T>(epsilon));
}

}// end namespace glm

#endif// GLM_QUATERNION_RELATIONAL_HPP_20240210220834
