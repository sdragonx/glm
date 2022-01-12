/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 functional.hpp

 2021-11-16 11:17:21

*/
#ifndef GLM_FUNCTIONAL_HPP_20211116111721
#define GLM_FUNCTIONAL_HPP_20211116111721

#include "../vec.hpp"



namespace glm{



/******************************************************************************
 *                                                                            *
 *                    genType compute( pfn, genType, ... )                    *
 *                                                                            *
 ******************************************************************************/

//
// vec<N, resultT> compute( in pfn, in vec<N, T> )
//

template<typename resultT, size_t N, typename T, typename PFN>
GLM_API vec<N, resultT> compute(PFN pfn, const vec<N, T>& v)
{
    vec<N, resultT> product;

    for (size_t i = 0; i < v.length(); ++i) {
        product[i] = pfn(v[i]);
    }
    
    return product;
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<2, resultT> compute(PFN pfn, const vec<2, T>& v)
{
    return vec<2, resultT>(pfn(v.x), pfn(v.y));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<3, resultT> compute( PFN pfn, const vec<3, T>& v)
{
    return vec<3, resultT>(pfn(v.x), pfn(v.y), pfn(v.z));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<4, resultT> compute(PFN pfn, const vec<4, T>& v)
{
    return vec<4, resultT>(PFN(v.x), PFN(v.y), PFN(v.z), PFN(v.w));
}

//
// vec<N, resultT> compute( in pfn, in vec<N, T>, in x )
//

template<typename resultT, size_t N, typename T, typename PFN>
GLM_API vec<N, resultT> compute(PFN pfn, const vec<N, T>& v, T x)
{
    vec<N, resultT> product;

    for (size_t i = 0; i < v.length(); ++i) {
        product[i] = pfn(v[i], x);
    }

    return product;
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<2, resultT> compute(PFN pfn, const vec<2, T>& v, T x)
{
    return vec<2, resultT>(pfn(v.x, x), pfn(v.y, x));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<3, resultT> compute(PFN pfn, const vec<3, T>& v, T x)
{
    return vec<3, resultT>(pfn(v.x, x), pfn(v.y, x), pfn(v.z, x));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<4, resultT> compute(PFN pfn, const vec<4, T>& v, T x)
{
    return vec<4, resultT>(pfn(v.x, x), pfn(v.y, x), pfn(v.z, x), pfn(v.w, x));
}

//
// vec<N, resultT> compute( in pfn, in vec<N, T>, in x, in y )
//

template<typename resultT, size_t N, typename T, typename PFN>
GLM_API vec<N, resultT> compute(PFN pfn, const vec<N, T>& v, T x, T y)
{
    vec<N, resultT> product;

    for (size_t i = 0; i < v.length(); ++i) {
        product[i] = pfn(v[i], x, y);
    }

    return product;
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<2, resultT> compute(PFN pfn, const vec<2, T>& v, T x, T y)
{
    return vec<2, resultT>(pfn(v.x, x, y), pfn(v.y, x, y));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<3, resultT> compute(PFN pfn, const vec<3, T>& v, T x, T y)
{
    return vec<3, resultT>(pfn(v.x, x, y), pfn(v.y, x, y), pfn(v.z, x, y));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<4, resultT> compute(PFN pfn, const vec<4, T>& v, T x, T y)
{
    return vec<4, resultT>(pfn(v.x, x, y), pfn(v.y, x, y), pfn(v.z, x, y), pfn(v.w, x, y));
}



/******************************************************************************
 *                                                                            *
 *              genType compute( pfn, genType, genType, ... )                 *
 *                                                                            *
 ******************************************************************************/

//
// vec<N, resultT> compute( in pfn, in vec<N, T>, in vec<N, T> )
//

template<typename resultT, size_t N, typename T, typename PFN>
GLM_API vec<N, resultT> compute(PFN pfn, const vec<N, T>& v1, const vec<N, T>& v2)
{
    vec<N, resultT> product;

    for (size_t i = 0; i < N; ++i) {
        product[i] = pfn(v1[i], v2[i]);
    }

    return product;
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<2, resultT> compute(PFN pfn, const vec<2, T>& v1, const vec<2, T>& v2)
{
    return vec<2, resultT>(pfn(v1.x, v2.x), pfn(v1.y, v2.y));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<3, resultT> compute(PFN pfn, const vec<3, T>& v1, const vec<3, T>& v2)
{
    return vec<3, resultT>(pfn(v1.x, v2.x), pfn(v1.y, v2.y), pfn(v1.z, v2.z));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<4, resultT> compute(PFN pfn, const vec<4, T>& v1, const vec<4, T>& v2)
{
    return vec<4, resultT>(pfn(v1.x, v2.x), pfn(v1.y, v2.y), pfn(v1.z, v2.z), pfn(v1.w, v2.w));
}

//
// vec<N, resultT> compute( in pfn, in vec<N, T>, in vec<N, T>, in x )
//

template<typename resultT, size_t N, typename T, typename PFN>
GLM_API vec<N, resultT> compute(PFN pfn, const vec<N, T>& v1, const vec<N, T>& v2, T x)
{
    vec<N, resultT> product;

    for (size_t i = 0; i < N; ++i) {
        product[i] = pfn(v1[i], v2[i], x);
    }

    return product;
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<2, resultT> compute(PFN pfn, const vec<2, T>& v1, const vec<2, T>& v2, T x)
{
    return vec<2, resultT>(pfn(v1.x, v2.x, x), pfn(v1.y, v2.y, x));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<3, resultT> compute(PFN pfn, const vec<3, T>& v1, const vec<3, T>& v2, T x)
{
    return vec<3, resultT>(pfn(v1.x, v2.x, x), pfn(v1.y, v2.y, x), pfn(v1.z, v2.z, x));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<4, resultT> compute(PFN pfn, const vec<4, T>& v1, const vec<4, T>& v2, T x)
{
    return vec<4, resultT>(pfn(v1.x, v2.x, x), pfn(v1.y, v2.y, x), pfn(v1.z, v2.z, x), pfn(v1.w, v2.w, x));
}

//
// vec<N, resultT> compute( in pfn, in vec<N, T>, in vec<N, T>, in x, in y )
//

template<typename resultT, size_t N, typename T, typename PFN>
GLM_API vec<N, resultT> compute(PFN pfn, const vec<N, T>& v1, const vec<N, T>& v2, T x, T y)
{
    vec<N, resultT> product;

    for (size_t i = 0; i < N; ++i) {
        product[i] = pfn(v1[i], v2[i], x, y);
    }

    return product;
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<2, resultT> compute(PFN pfn, const vec<2, T>& v1, const vec<2, T>& v2, T x, T y)
{
    return vec<2, resultT>(pfn(v1.x, v2.x, x, y), pfn(v1.y, v2.y, x, y));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<3, resultT> compute(PFN pfn, const vec<3, T>& v1, const vec<3, T>& v2, T x, T y)
{
    return vec<3, resultT>(pfn(v1.x, v2.x, x, y), pfn(v1.y, v2.y, x, y), pfn(v1.z, v2.z, x, y));
}

template<typename resultT, typename T, typename PFN>
GLM_API vec<4, resultT> compute(PFN pfn, const vec<4, T>& v1, const vec<4, T>& v2, T x, T y)
{
    return vec<4, resultT>(pfn(v1.x, v2.x, x, y), pfn(v1.y, v2.y, x, y), pfn(v1.z, v2.z, x, y), pfn(v1.w, v2.w, x, y));
}



/******************************************************************************
 *                                                                            *
 *                         bool judge( pfn, genType )                         *
 *                                                                            *
 ******************************************************************************/

template<typename T, typename PFN>
GLM_API bool judge(PFN pfn, const T& v)
{
    return PFN(v);
}

template<typename T, typename PFN>
GLM_API bool judge(PFN pfn, const vec<2, T>& v)
{
    return pfn(v.x) && pfn(v.y);
}

template<typename T, typename PFN>
GLM_API bool judge(PFN pfn, const vec<3, T>& v)
{
    return pfn(v.x) && pfn(v.y) && pfn(v.z);
}

template<typename T, typename PFN>
GLM_API bool judge(PFN pfn, const vec<4, T>& v)
{
    return pfn(v.x) && pfn(v.y) && pfn(v.z) && pfn(v.w);
}

/******************************************************************************
 *                                                                            *
 *                  bool compare( pfn, genType, genType )                     *
 *                                                                            *
 ******************************************************************************/

//
// bool compare( in pfn, in vec<N, T>, in vec<N, T> )
//

template<size_t N, typename T, typename PFN>
GLM_API bool compare(PFN pfn, const vec<N, T>& v1, const vec<N, T>& v2)
{
    for (size_t i = 0; i < N; ++i) {
        if(pfn(v1[i], v2[i]) == false) {
            return false;
        }
    }

    return true;
}

template<typename T, typename PFN>
GLM_API bool compare(PFN pfn, const vec<2, T>& v1, const vec<2, T>& v2)
{
    return pfn(v1.x, v2.x) && pfn(v1.y, v2.y);
}

template<typename T, typename PFN>
GLM_API bool compare(PFN pfn, const vec<3, T>& v1, const vec<3, T>& v2)
{
    return pfn(v1.x, v2.x) && pfn(v1.y, v2.y) && pfn(v1.z, v2.z);
}

template<typename T, typename PFN>
GLM_API bool compare(PFN pfn, const vec<4, T>& v1, const vec<4, T>& v2)
{
    return pfn(v1.x, v2.x) && pfn(v1.y, v2.y) && pfn(v1.z, v2.z) && pfn(v1.w, v2.w);
}

}// end namespace glm

#endif// GLM_FUNCTIONAL_HPP_20211116111721
