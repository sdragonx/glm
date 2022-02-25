/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 float.hpp

 2022-02-25 14:15:15

*/
#ifndef GLM_FLOAT_HPP_20220225141515
#define GLM_FLOAT_HPP_20220225141515

#include "setup.hpp"

namespace glm {

#if !defined(FP_INFINITE) && !defined(FP_NAN)

template<typename T>
GLM_API bool isinf(const T& n)
{
     return _finite(n);
}

template<typename T>
GLM_API bool isnan(const T& n)
{
    return _isnan(n);
}

#else

template<typename T>
GLM_API bool isinf(const T& n)
{
    return std::isinf(n);
}

template<typename T>
GLM_API bool isnan(const T& n)
{
    return std::isnan(n);
}

#endif

}// end namespace cgl

#endif// GLM_FLOAT_HPP_20220225141515
