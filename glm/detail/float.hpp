/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 float.hpp

 2022-02-25 14:15:15

*/
#ifndef GLM_FLOAT_HPP_20220225141515
#define GLM_FLOAT_HPP_20220225141515

#include "setup.hpp"

namespace glm {

#if defined(GLM_NATIVE_CPP11_SUPPORT)

using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::signbit;

#elif defined(_FPCLASS_SNAN) || defined(FP_SNAN)

//
// fpclass
//

GLM_API bool isfinite(double n)
{
    return _finite(n);
}

GLM_API bool isinf(double n)
{
    return _fpclass(n) & (_FPCLASS_NINF | _FPCLASS_PINF);
}

GLM_API bool isnan(double n)
{
    //return _fpclass(n) & (_FPCLASS_SNAN | _FPCLASS_QNAN);
    return _isnan(n);
}

GLM_API bool isnormal(double n)
{
    return _fpclass(n) & (_FPCLASS_NN | _FPCLASS_PN);
}

GLM_API bool signbit(double n)
{
    return n < 0.0;
}

#elif defined(FP_INFINITE)

//
// __fpclassify()       // msvc
//

template<typename T>
bool isfinite(T value)
{
    return fpclassify(T) <= 0;
}

template<typename T>
bool isinf(T value)
{
    return fpclassify(value) == FP_INFINITE;
}

template<typename T>
bool isnan(T value)
{
    return fpclassify(value) == FP_NAN;
}

template<typename T>
bool isnormal(T value)
{
    return fpclassify(value) == FP_NORMAL;
}

bool signbit(float value)
{
    return _fdsign(value);
}

bool signbit(double value)
{
    return _dsign(value);
}

bool signbit(long double value)
{
    return _ldsign(value);
}

#endif

}// end namespace cgl

#endif// GLM_FLOAT_HPP_20220225141515
