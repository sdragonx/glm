/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 matrix_projection.hpp

 2021-11-13 21:48:49

*/
#ifndef GLM_MATRIX_PROJECTION_HPP_20211113214849
#define GLM_MATRIX_PROJECTION_HPP_20211113214849

#include "matrix_transform.hpp"



namespace glm {

//
// project
//

template<typename T, typename V>
GLM_API vec<4, T> project(
    const vec<4, T>& v,
    const mat<4, 4, T>& modelview,
    const mat<4, 4, T>& projection,
    const vec<4, V>& viewport)
{
    vec<4, T> product = modelview * v;
    product = projection * product;

    /* 透视除法
     */
    product /= product.w;

    /* 映射到 0 ~ 1
     */
    product = product * constants<T>::half + constants<T>::half;

    /* 转换到屏幕坐标
     */
    const T x = static_cast<T>(viewport[0]);
    const T y = static_cast<T>(viewport[1]);
    const T w = static_cast<T>(viewport[2]);
    const T h = static_cast<T>(viewport[3]);

    product.x = product.x * w + x;
    product.y = product.y * h + y;

    return product;
}

template<typename T, typename V>
GLM_API vec<3, T> project(
    const vec<3, T>& v,
    const mat<4, 4, T>& modelview,
    const mat<4, 4, T>& projection,
    const vec<4, V>& viewport)
{
    return vec<3, T>(project(vec<4, T>(v, constants<T>::one), modelview, projection, viewport));
}

//
// unProject
//

template<typename T, typename V>
vec<4, T> unProject(const vec<4, T>& win,
    const mat<4, 4, T>& modelview,
    const mat<4, 4, T>& projection,
    const vec<4, V>& viewport)
{
    // Calculation for inverting a matrix, compute projection x modelview
    mat<4, 4, T> m = projection * modelview;

    // Now compute the inverse of matrix A
    m = inverse(m);
    //assert(m)

    // Transformation of normalized coordinates between -1 and 1
    const T x = static_cast<T>(viewport[0]);
    const T y = static_cast<T>(viewport[1]);
    const T w = static_cast<T>(viewport[2]);
    const T h = static_cast<T>(viewport[3]);

    vec<4, T> product = vec<4, T>((win.x - x) / w, (win.y - y) / h, win.z, constants<T>::one);
    product = product * constants<T>::two - constants<T>::one;

    // Objects coordinates
    product = m * product;

    if (abs(product.w) < constants<T>::epsilon) {
        return vec<4, T>();
    }

    T d = constants<T>::one / product.w;
    product.x *= d;
    product.y *= d;
    product.z *= d;
    product.w = constants<T>::one;

    return product;
}

template<typename T, typename V>
vec<3, T> unProject(const vec<3, T>& win,
    const mat<4, 4, T>& modelview,
    const mat<4, 4, T>& projection,
    const vec<4, V>& viewport)
{
    return unProject(vec<4, T>(win, constants<T>::one), modelview, projection, viewport);
}

}// end namespace glm

#endif// GLM_MATRIX_PROJECTION_HPP_20211113214849
