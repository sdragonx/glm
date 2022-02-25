/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 functional.hpp

 2021-11-16 11:17:21

*/
#ifndef GLM_FUNCTIONAL_HPP_20211116111721
#define GLM_FUNCTIONAL_HPP_20211116111721

#include "../vec2.hpp"
#include "../vec3.hpp"
#include "../vec4.hpp"



namespace glm {

template<typename R, typename T>
struct functional
{
    typedef R (*single) (const T&);
    typedef R (*dual  ) (const T&, const T&);
    typedef R (*triple) (const T&, const T&, const T&);
    typedef R (*quad  ) (const T&, const T&, const T&, const T&);
};

/******************************************************************************
 *                                                                            *
 *                          struct compute<R, N, T>                           *
 *                                                                            *
 ******************************************************************************/

//
// vecX compute( in vecX )
// vecX compute( in vecX, in vecX )
// vecX compute( in vecX, in vecX, in T )
// vecX compute( in vecX, in vecX, in T, in T )
//

template<typename R, size_t N, typename T>
struct compute
{
    static vec<N, R> invoke(typename functional<R, T>::single pfn, const vec<N, T>& v)
    {
        vec<N, R> product;

        for (size_t i = 0; i < v.length(); ++i) {
            product[i] = pfn(v[i]);
        }

        return product;
    }

    static vec<N, R> invoke(typename functional<R, T>::dual pfn, const vec<N, T>& v, const T& x)
    {
        vec<N, R> product;

        for (size_t i = 0; i < v.length(); ++i) {
            product[i] = pfn(v[i], x);
        }

        return product;
    }

    static vec<N, R> invoke(typename functional<R, T>::triple pfn, const vec<N, T>& v, const T& x, const T& y)
    {
        vec<N, R> product;

        for (size_t i = 0; i < v.length(); ++i) {
            product[i] = pfn(v[i], x, y);
        }

        return product;
    }



    static vec<N, R> invoke(typename functional<R, T>::dual pfn, const vec<N, T>& v1, const vec<N, T>& v2)
    {
        vec<N, R> product;

        for (size_t i = 0; i < v1.length(); ++i) {
            product[i] = pfn(v1[i], v2[i]);
        }

        return product;
    }

    static vec<N, R> invoke(typename functional<R, T>::triple pfn, const vec<N, T>& v1, const vec<N, T>& v2, const T& x)
    {
        vec<N, R> product;

        for (size_t i = 0; i < v1.length(); ++i) {
            product[i] = pfn(v1[i], v2[i], x);
        }

        return product;
    }

    static vec<N, R> invoke(typename functional<R, T>::quad pfn, const vec<N, T>& v1, const vec<N, T>& v2, const T& x, const T& y)
    {
        vec<N, R> product;

        for (size_t i = 0; i < v1.length(); ++i) {
            product[i] = pfn(v1[i], v2[i], x, y);
        }

        return product;
    }
};

template<typename R, typename T>
struct compute<R, 2, T>
{
    static vec<2, R> invoke(typename functional<R, T>::single pfn, const vec<2, T>& v)
    {
        return vec<2, R>(pfn(v[0]), pfn(v[1]));
    }

    static vec<2, R> invoke(typename functional<R, T>::dual pfn, const vec<2, T>& v1, const vec<2, T>& v2)
    {
        return vec<2, R>(pfn(v1[0], v2[0]), pfn(v1[1], v2[1]));
    }

    static vec<2, R> invoke(typename functional<R, T>::triple pfn, const vec<2, T>& v1, const vec<2, T>& v2, const T& x)
    {
        return vec<2, R>(pfn(v1[0], v2[0], x), pfn(v1[1], v2[1], x));
    }

    static vec<2, R> invoke(typename functional<R, T>::quad pfn, const vec<2, T>& v1, const vec<2, T>& v2, const T& x, const T& y)
    {
        return vec<2, R>(pfn(v1[0], v2[0], x, y), pfn(v1[1], v2[1], x, y));
    }
};

template<typename R, typename T>
struct compute<R, 3, T>
{
    static vec<3, R> invoke(typename functional<R, T>::single pfn, const vec<3, T>& v)
    {
        return vec<3, R>(pfn(v[0]), pfn(v[1]), pfn(v[2]));
    }

    static vec<3, R> invoke(typename functional<R, T>::dual pfn, const vec<3, T>& v1, const vec<3, T>& v2)
    {
        return vec<3, R>(pfn(v1[0], v2[0]), pfn(v1[1], v2[1]), pfn(v1[2], v2[2]));
    }

    static vec<3, R> invoke(typename functional<R, T>::triple pfn, const vec<3, T>& v1, const vec<3, T>& v2, const T& x)
    {
        return vec<3, R>(pfn(v1[0], v2[0], x), pfn(v1[1], v2[1], x), pfn(v1[2], v2[2], x));
    }

    static vec<3, R> invoke(typename functional<R, T>::quad pfn, const vec<3, T>& v1, const vec<3, T>& v2, const T& x, const T& y)
    {
        return vec<3, R>(pfn(v1[0], v2[0], x, y), pfn(v1[1], v2[1], x, y), pfn(v1[2], v2[2], x, y));
    }
};

template<typename R, typename T>
struct compute<R, 4, T>
{
    static vec<4, R> invoke(typename functional<R, T>::single pfn, const vec<4, T>& v)
    {
        return vec<4, R>(pfn(v[0]), pfn(v[1]), pfn(v[2]), pfn(v[3]));
    }

    static vec<4, R> invoke(typename functional<R, T>::dual pfn, const vec<4, T>& v, const T& x)
    {
        return vec<4, R>(pfn(v[0], x), pfn(v[1], x), pfn(v[2], x), pfn(v[3], x));
    }

    static vec<4, R> invoke(typename functional<R, T>::triple pfn, const vec<4, T>& v, const T& x, const T& y)
    {
        return vec<4, R>(pfn(v[0], x, y), pfn(v[1], x, y), pfn(v[2], x, y), pfn(v[3], x, y));
    }



    static vec<4, R> invoke(typename functional<R, T>::dual pfn, const vec<4, T>& v1, const vec<4, T>& v2)
    {
        return vec<4, R>(pfn(v1[0], v2[0]), pfn(v1[1], v2[1]), pfn(v1[2], v2[2]), pfn(v1[3], v2[3]));
    }

    static vec<4, R> invoke(typename functional<R, T>::triple pfn, const vec<4, T>& v1, const vec<4, T>& v2, const T& x)
    {
        return vec<4, R>(pfn(v1[0], v2[0], x), pfn(v1[1], v2[1], x), pfn(v1[2], v2[2], x), pfn(v1[3], v2[3], x));
    }

    static vec<4, R> invoke(typename functional<R, T>::quad pfn, const vec<4, T>& v1, const vec<4, T>& v2, const T& x, const T& y)
    {
        return vec<4, R>(pfn(v1[0], v2[0], x, y), pfn(v1[1], v2[1], x, y), pfn(v1[2], v2[2], x, y), pfn(v1[3], v2[3], x, y));
    }
};

/******************************************************************************
 *                                                                            *
 *                             logical_and<N, T>                              *
 *                                                                            *
 ******************************************************************************/

//
// bool logical_and::invoke( in pfn, in vecX )
// bool logical_and::invoke( in pfn, in vecX, in vecX )
//

template<size_t N, typename T>
struct logical_and
{
    static bool invoke(typename functional<bool, T>::single pfn, const vec<N, T>& v)
    {
        for (size_t i = 0; i < N; ++i) {
            if(pfn(v) == false) {
                return false;
            }
        }

        return true;
    }

    static bool invoke(typename functional<bool, T>::dual pfn, const vec<N, T>& v1, const vec<N, T>& v2)
    {
        for (size_t i = 0; i < N; ++i) {
            if(pfn(v1[i], v2[i]) == false) {
                return false;
            }
        }

        return true;
    }
};

template<typename T>
struct logical_and<2, T>
{
    static bool invoke(typename functional<bool, T>::single pfn, const vec<2, T>& v)
    {
        return pfn(v.x) && pfn(v.y);
    }

    static bool invoke(typename functional<bool, T>::dual pfn, const vec<2, T>& v1, const vec<2, T>& v2)
    {
        return pfn(v1.x, v2.x) && pfn(v1.y, v2.y);
    }
};

template<typename T>
struct logical_and<3, T>
{
    static bool invoke(typename functional<bool, T>::single pfn, const vec<3, T>& v)
    {
        return pfn(v.x) && pfn(v.y) && pfn(v.z);
    }

    static bool invoke(typename functional<bool, T>::dual pfn, const vec<3, T>& v1, const vec<3, T>& v2)
    {
        return pfn(v1.x, v2.x) && pfn(v1.y, v2.y) && pfn(v1.z, v2.z);
    }
};

template<typename T>
struct logical_and<4, T>
{
    static bool invoke(typename functional<bool, T>::single pfn, const vec<4, T>& v)
    {
        return pfn(v.x) && pfn(v.y) && pfn(v.z) && pfn(v.w);
    }

    static bool invoke(typename functional<bool, T>::dual pfn, const vec<4, T>& v1, const vec<4, T>& v2)
    {
        return pfn(v1.x, v2.x) && pfn(v1.y, v2.y) && pfn(v1.z, v2.z) && pfn(v1.w, v2.w);
    }
};

/******************************************************************************
 *                                                                            *
 *                             logical_or<N, T>                               *
 *                                                                            *
 ******************************************************************************/

//
// bool logical_or::invoke( in pfn, in vecX )
// bool logical_or::invoke( in pfn, in vecX, in vecX )
//

template<size_t N, typename T>
struct logical_or
{
    static bool invoke(typename functional<bool, T>::single pfn, const vec<N, T>& v)
    {
        for (size_t i = 0; i < N; ++i) {
            if(pfn(v) == true) {
                return true;
            }
        }

        return false;
    }

    static bool invoke(typename functional<bool, T>::dual pfn, const vec<N, T>& v1, const vec<N, T>& v2)
    {
        for (size_t i = 0; i < N; ++i) {
            if(pfn(v1[i], v2[i]) == true) {
                return true;
            }
        }

        return false;
    }
};

template<typename T>
struct logical_or<2, T>
{
    static bool invoke(typename functional<bool, T>::single pfn, const vec<2, T>& v)
    {
        return pfn(v.x) || pfn(v.y);
    }

    static bool invoke(typename functional<bool, T>::dual pfn, const vec<2, T>& v1, const vec<2, T>& v2)
    {
        return pfn(v1.x, v2.x) || pfn(v1.y, v2.y);
    }
};

template<typename T>
struct logical_or<3, T>
{
    static bool invoke(typename functional<bool, T>::single pfn, const vec<3, T>& v)
    {
        return pfn(v.x) || pfn(v.y) || pfn(v.z);
    }

    static bool invoke(typename functional<bool, T>::dual pfn, const vec<3, T>& v1, const vec<3, T>& v2)
    {
        return pfn(v1.x, v2.x) || pfn(v1.y, v2.y) || pfn(v1.z, v2.z);
    }
};

template<typename T>
struct logical_or<4, T>
{
    static bool invoke(typename functional<bool, T>::single pfn, const vec<4, T>& v)
    {
        return pfn(v.x) || pfn(v.y) || pfn(v.z) || pfn(v.w);
    }

    static bool invoke(typename functional<bool, T>::dual pfn, const vec<4, T>& v1, const vec<4, T>& v2)
    {
        return pfn(v1.x, v2.x) || pfn(v1.y, v2.y) || pfn(v1.z, v2.z) || pfn(v1.w, v2.w);
    }
};

}// end namespace glm

#endif// GLM_FUNCTIONAL_HPP_20211116111721
