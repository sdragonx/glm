/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 spline.hpp

 2024-01-18 21:11:21

*/
#ifndef GLM_SPLINE_HPP_20240118211121
#define GLM_SPLINE_HPP_20240118211121

#include "../vector.hpp"



namespace glm {

template<size_t N, typename T>
vec<N, T> catmullRom(const vec<N, T>& v1, const vec<N, T>& v2, const vec<N, T>& v3, const vec<N, T>& v4, const T& s)
{
    T s2 = pow2(s);
    T s3 = pow3(s);

    T f1 = -s3 + T(2) * s2 - s;
    T f2 = T(3) * s3 - T(5) * s2 + T(2);
    T f3 = T(-3) * s3 + T(4) * s2 + s;
    T f4 = s3 - s2;

    return (f1 * v1 + f2 * v2 + f3 * v3 + f4 * v4) / T(2);
}

template<size_t N, typename T>
vec<N, T> hermite(const vec<N, T>& v1, const vec<N, T>& t1, const vec<N, T>& v2, const vec<N, T>& t2, const T& s)
{
    T s2 = pow2(s);
    T s3 = pow3(s);

    T f1 = T(2) * s3 - T(3) * s2 + T(1);
    T f2 = T(-2) * s3 + T(3) * s2;
    T f3 = s3 - T(2) * s2 + s;
    T f4 = s3 - s2;

    return f1 * v1 + f2 * v2 + f3 * t1 + f4 * t2;
}

template<size_t N, typename T>
vec<N, T> cubic(const vec<N, T>& v1, const vec<N, T>& v2, const vec<N, T>& v3, const vec<N, T>& v4, const T& s)
{
    return ((v1 * s + v2) * s + v3) * s + v4;
}

}// end namespace glm

#endif// GLM_SPLINE_HPP_20240118211121
