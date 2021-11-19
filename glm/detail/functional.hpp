/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 functional.hpp

 2021-11-16 11:17:21

*/
#ifndef FUNCTIONAL_HPP_20211116111721
#define FUNCTIONAL_HPP_20211116111721

#include "../vec.hpp"

namespace cgl{
namespace glm{

/******************************************************************************
 *                                                                            *
 *                      genT compute( pfn, genT, ... )                        *
 *                                                                            *
 ******************************************************************************/

//
// vec<N, T> compute( in pfn, in vec<N, T> )
//

template<size_t N, typename T, typename PFN>
GLM_API vec<N, T> compute(PFN pfn, const vec<N, T>& v)
{
    vec<N, T> product;

    for (size_t i = 0; i < v.length(); ++i) {
        product[i] = pfn(v[i]);
    }
    
    return product;
}

template<typename T, typename PFN>
GLM_API vec<2, T> compute(PFN pfn, const vec<2, T>& v)
{
    return vec<2, T>(pfn(v.x), pfn(v.y));
}

template<typename T, typename PFN>
GLM_API vec<3, T> compute( PFN pfn, const vec<3, T>& v)
{
    return vec<3, T>(pfn(v.x), pfn(v.y), pfn(v.z));
}

template<typename T, typename PFN>
GLM_API vec<4, T> compute(PFN pfn, const vec<4, T>& v)
{
    return vec<4, T>(PFN(v.x), PFN(v.y), PFN(v.z), PFN(v.w));
}

//
// vec<N, T> compute( in pfn, in vec<N, T>, in x )
//

template<size_t N, typename T, typename PFN>
GLM_API vec<N, T> compute(PFN pfn, const vec<N, T>& v, T x)
{
    vec<N, T> product;

    for (size_t i = 0; i < v.length(); ++i) {
        product[i] = pfn(v[i], x);
    }

    return product;
}

template<typename T, typename PFN>
GLM_API vec<2, T> compute(PFN pfn, const vec<2, T>& v, T x)
{
    return vec<2, T>(pfn(v.x, x), pfn(v.y, x));
}

template<typename T, typename PFN>
GLM_API vec<3, T> compute(PFN pfn, const vec<3, T>& v, T x)
{
    return vec<3, T>(pfn(v.x, x), pfn(v.y, x), pfn(v.z, x));
}

template<typename T, typename PFN>
GLM_API vec<4, T> compute(PFN pfn, const vec<4, T>& v, T x)
{
    return vec<4, T>(pfn(v.x, x), pfn(v.y, x), pfn(v.z, x), pfn(v.w, x));
}

//
// vec<N, T> compute( in pfn, in vec<N, T>, in x, in y )
//

template<size_t N, typename T, typename PFN>
GLM_API vec<N, T> compute(PFN pfn, const vec<N, T>& v, T x, T y)
{
    vec<N, T> product;

    for (size_t i = 0; i < v.length(); ++i) {
        product[i] = pfn(v[i], x, y);
    }

    return product;
}

template<typename T, typename PFN>
GLM_API vec<2, T> compute(PFN pfn, const vec<2, T>& v, T x, T y)
{
    return vec<2, T>(pfn(v.x, x, y), pfn(v.y, x, y));
}

template<typename T, typename PFN>
GLM_API vec<3, T> compute(PFN pfn, const vec<3, T>& v, T x, T y)
{
    return vec<3, T>(pfn(v.x, x, y), pfn(v.y, x, y), pfn(v.z, x, y));
}

template<typename T, typename PFN>
GLM_API vec<4, T> compute(PFN pfn, const vec<4, T>& v, T x, T y)
{
    return vec<4, T>(pfn(v.x, x, y), pfn(v.y, x, y), pfn(v.z, x, y), pfn(v.w, x, y));
}



/******************************************************************************
 *                                                                            *
 *                 genT compute( pfn, genT, genT, ... )                       *
 *                                                                            *
 ******************************************************************************/

//
// vec<N, T> compute( in pfn, in vec<N, T>, in vec<N, T> )
//

template<size_t N, typename T, typename PFN>
GLM_API vec<N, T> compute(PFN pfn, const vec<N, T>& v1, const vec<N, T>& v2)
{
    vec<N, T> product;

    for (size_t i = 0; i < N; ++i) {
        product[i] = pfn(v1[i], v2[i]);
    }

    return product;
}

template<typename T, typename PFN>
GLM_API vec<2, T> compute(PFN pfn, const vec<2, T>& v1, const vec<2, T>& v2)
{
    return vec<2, T>(pfn(v1.x, v2.x), pfn(v1.y, v2.y));
}

template<typename T, typename PFN>
GLM_API vec<3, T> compute(PFN pfn, const vec<3, T>& v1, const vec<3, T>& v2)
{
    return vec<3, T>(pfn(v1.x, v2.x), pfn(v1.y, v2.y), pfn(v1.z, v2.z));
}

template<typename T, typename PFN>
GLM_API vec<4, T> compute(PFN pfn, const vec<4, T>& v1, const vec<4, T>& v2)
{
    return vec<4, T>(pfn(v1.x, v2.x), pfn(v1.y, v2.y), pfn(v1.z, v2.z), pfn(v1.w, v2.w));
}

//
// vec<N, T> compute( in pfn, in vec<N, T>, in vec<N, T>, in x )
//

template<size_t N, typename T, typename PFN>
GLM_API vec<N, T> compute(PFN pfn, const vec<N, T>& v1, const vec<N, T>& v2, T x)
{
    vec<N, T> product;

    for (size_t i = 0; i < N; ++i) {
        product[i] = pfn(v1[i], v2[i], x);
    }

    return product;
}

template<typename T, typename PFN>
GLM_API vec<2, T> compute(PFN pfn, const vec<2, T>& v1, const vec<2, T>& v2, T x)
{
    return vec<2, T>(pfn(v1.x, v2.x, x), pfn(v1.y, v2.y, x));
}

template<typename T, typename PFN>
GLM_API vec<3, T> compute(PFN pfn, const vec<3, T>& v1, const vec<3, T>& v2, T x)
{
    return vec<3, T>(pfn(v1.x, v2.x, x), pfn(v1.y, v2.y, x), pfn(v1.z, v2.z, x));
}

template<typename T, typename PFN>
GLM_API vec<4, T> compute(PFN pfn, const vec<4, T>& v1, const vec<4, T>& v2, T x)
{
    return vec<4, T>(pfn(v1.x, v2.x, x), pfn(v1.y, v2.y, x), pfn(v1.z, v2.z, x), pfn(v1.w, v2.w, x));
}

//
// vec<N, T> compute( in pfn, in vec<N, T>, in vec<N, T>, in x, in y )
//

template<size_t N, typename T, typename PFN>
GLM_API vec<N, T> compute(PFN pfn, const vec<N, T>& v1, const vec<N, T>& v2, T x, T y)
{
    vec<N, T> product;

    for (size_t i = 0; i < N; ++i) {
        product[i] = pfn(v1[i], v2[i], x, y);
    }

    return product;
}

template<typename T, typename PFN>
GLM_API vec<2, T> compute(PFN pfn, const vec<2, T>& v1, const vec<2, T>& v2, T x, T y)
{
    return vec<2, T>(pfn(v1.x, v2.x, x, y), pfn(v1.y, v2.y, x, y));
}

template<typename T, typename PFN>
GLM_API vec<3, T> compute(PFN pfn, const vec<3, T>& v1, const vec<3, T>& v2, T x, T y)
{
    return vec<3, T>(pfn(v1.x, v2.x, x, y), pfn(v1.y, v2.y, x, y), pfn(v1.z, v2.z, x, y));
}

template<typename T, typename PFN>
GLM_API vec<4, T> compute(PFN pfn, const vec<4, T>& v1, const vec<4, T>& v2, T x, T y)
{
    return vec<4, T>(pfn(v1.x, v2.x, x, y), pfn(v1.y, v2.y, x, y), pfn(v1.z, v2.z, x, y), pfn(v1.w, v2.w, x, y));
}

}// end namespace glm
}// end namespace cgl

#endif// FUNCTIONAL_HPP_20211116111721
