/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 geometric.hpp

 2021-11-15 20:31:03

*/
#ifndef GLM_GEOMETRIC_HPP_20211115203103
#define GLM_GEOMETRIC_HPP_20211115203103

#include "detail/functions.hpp"
#include "detail/functional.hpp"
#include "trigonometric.hpp"
#include "vec.hpp"



namespace glm{

//
// T dot( in vec<N, T>, in vec<N, T> )
//

template<size_t N, typename T>
GLM_API T dot(const vec<N, T>& a, const vec<N, T>& b)
{
    T n = T();
    for(size_t i = 0; i < N; ++i) {
        n += a[i] * b[i];
    }
    return n;
}

template<typename T>
GLM_API T dot(const vec<2, T>& x, const vec<2, T>& y)
{
    return x.x * y.x + x.y * y.y;
}

template<typename T>
GLM_API T dot(const vec<3, T>& x, const vec<3, T>& y)
{
    return x.x * y.x + x.y * y.y + x.z * y.z;
}

template<typename T>
GLM_API T dot(const vec<4, T>& x, const vec<4, T>& y)
{
    return x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w;
}

//
// T length( in vec<N, T> )
//

template<size_t N, typename T>
GLM_API T length(const vec<N, T>& v)
{
    return sqrt(dot(v, v));
}

//
// T distance( in vec<N, T>, in vec<N, T> )
//

template<size_t N, typename T>
GLM_API T distance(const vec<N, T>& a, const vec<N, T>& b)
{
    return length(b - a);
}

//
// vec3 cross( in vec3, in vec3 )
//


/* 叉乘
 *
 * 返回两个向量的垂直向量
 */
template<typename T>
vec<3, T> cross(const vec<3, T>& v1, const vec<3, T>& v2)
{
    return vec<3, T>(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    );
}

//
// vec<N, T> normalize( in vec<N, T> )
//

template<size_t N, typename T>
GLM_API vec<N, T> normalize(const vec<N, T>& v)
{
    T n = constants<T>::one / (length(v) + std::numeric_limits<T>::epsilon());
    return v * n;
}

/* T faceforward( in T, in T, in Nref )
 *
 * dot(Nref, I) < 0 则 N, 否则 -N
 */

template<typename T>
GLM_API T faceforward(const T& N, const T& I, const T& Nref)
{
	return dot(Nref, I) < constants<T>::zero ? N : -N;
}

/* vec3 reflect( in vec3, in vec3 )
 *
 * 反射方向计算
 *
 * I    入射角度
 * N    法线
 */
template<typename T>
vec<3, T> reflect(const vec<3, T>& I, const vec<3, T>& N)
{
    return I - N * dot(N, I) * constants<T>::two;
}

/* vec3 refract( in vec3, in vec3, in T )
 *
 * 折射方向计算
 *
 * I    入射角度
 * N    法线
 * eta  物体折射率
 */
template<typename T>
vec<3, T> refract(const vec<3, T>& I, const vec<3, T>& N, T eta)
{
    T d = dot(I, N);
    T k = constants<T>::one - eta * eta * (constants<T>::one - d * d);
    if (k > constants<T>::zero) {
        return eta * (I - N * d) - N * sqrt(k);
    }
    else {
        return vec<3, T>();
    }
}

}// end namespace glm

#endif// GLM_GEOMETRIC_HPP_20211115203103
