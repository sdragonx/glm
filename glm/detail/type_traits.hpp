/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 type_traits.hpp

 2021-11-15 20:21:42

*/
#ifndef GLM_TYPE_TRAITS_HPP_20211115202142
#define GLM_TYPE_TRAITS_HPP_20211115202142

#include "constants.hpp"



namespace glm {


template<typename T>
class type_traits : public constants<T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    // to boolean
    static bool judge(const T& value)
    {
        return value != static_cast<T>(0);
    }

    static bool isZero(const T& value)
    {
        return value == static_cast<T>(0);
    }

    // numerical
    static bool isfinite(const T& value);
    static bool isinf(const T& value);
    static bool isnan(const T& value);
    static bool isnormal(const T& value);
    static bool signbit(const T& value);

    // boolean logic operations
    static bool Not(const T& value) { return !value; }
    static bool less(const T& x, const T& y) { return x < y; }
    static bool lessEqual(const T& x, const T& y) { return x <= y; }
    static bool greater(const T& x, const T& y) { return x > y; }
    static bool greaterEqual(const T& x, const T& y) { return x >= y; }
    static bool equal(const T& x, const T& y) { return x == y; }
    static bool notEqual(const T& x, const T& y) { return !equal(x, y); }

    // return the identity value of type.
    static T identity()
    {
        return T();
    }
};

//------------------------------------------------------------------------------
// numerical
//------------------------------------------------------------------------------

// bool isZero ( real type )

template<>
GLM_API bool type_traits<float>::isZero(const float& value)
{
    return value < zero ? -value < epsilon : value < epsilon;
}

template<>
GLM_API bool type_traits<double>::isZero(const double& value)
{
    return value < zero ? -value < epsilon : value < epsilon;
}

template<>
GLM_API bool type_traits<long double>::isZero(const long double& value)
{
    return value < zero ? -value < epsilon : value < epsilon;
}

// bool judge( real type )

template<>
GLM_API bool type_traits<float>::judge(const float& value)
{
    return !isZero(value);
}

template<>
GLM_API bool type_traits<double>::judge(const double& value)
{
    return !isZero(value);
}

template<>
GLM_API bool type_traits<long double>::judge(const long double& value)
{
    return !isZero(value);
}

// clang-format off
#if defined(GLM_NATIVE_CPP11_SUPPORT)

template<typename T>
bool type_traits<T>::isfinite(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isfinite' only accept floating-point inputs");
    return std::isfinite(value);
}

template<typename T>
bool type_traits<T>::isinf(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isinf' only accept floating-point inputs");
    return std::isinf(value);
}

template<typename T>
bool type_traits<T>::isnan(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isnan' only accept floating-point inputs");
    return std::isnan(value);
}

template<typename T>
bool type_traits<T>::isnormal(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isnormal' only accept floating-point inputs");
    return std::isnormal(value);
}

template<typename T>
bool type_traits<T>::signbit(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'signbit' only accept floating-point inputs");
    return std::signbit(value);
}

#elif defined(_FPCLASS_SNAN) || defined(FP_SNAN)

//
// fpclass
//

template<typename T>
bool type_traits<T>::isfinite(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isfinite' only accept floating-point inputs");
    return _finite(value);
}

template<typename T>
bool type_traits<T>::isinf(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isinf' only accept floating-point inputs");
    return _fpclass(value) & (_FPCLASS_NINF | _FPCLASS_PINF);
}

template<typename T>
bool type_traits<T>::isnan(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isnan' only accept floating-point inputs");
    //return _fpclass(value) & (_FPCLASS_SNAN | _FPCLASS_QNAN);
    return _isnan(value);
}

template<typename T>
bool type_traits<T>::isnormal(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isnormal' only accept floating-point inputs");
    return _fpclass(value) & (_FPCLASS_NN | _FPCLASS_PN);
}

template<typename T>
bool type_traits<T>::signbit(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'signbit' only accept floating-point inputs");
    return value < static_cast<T>(0);
}

#elif defined(FP_INFINITE)

//
// __fpclassify()       // msvc
//

template<typename T>
bool type_traits<T>::isfinite(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isfinite' only accept floating-point inputs");
    return fpclassify(T) <= 0;
}

template<typename T>
bool type_traits<T>::isinf(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isinf' only accept floating-point inputs");
    return fpclassify(value) == FP_INFINITE;
}

template<typename T>
bool type_traits<T>::isnan(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isnan' only accept floating-point inputs");
    return fpclassify(value) == FP_NAN;
}

template<typename T>
bool type_traits<T>::isnormal(const T& value)
{
    GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isnormal' only accept floating-point inputs");
    return fpclassify(value) == FP_NORMAL;
}

template<>
bool type_traits<float>::signbit(float value)
{
    // GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'signbit' only accept floating-point inputs");
    return _fdsign(value);
}

template<>
bool type_traits<double>::signbit(double value)
{
    // GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'signbit' only accept floating-point inputs");
    return _dsign(value);
}

template<>
bool type_traits<long double>::signbit(long double value)
{
    // GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'signbit' only accept floating-point inputs");
    return _ldsign(value);
}

#endif
// clang-format on

//------------------------------------------------------------------------------
// boolean logic operations
//------------------------------------------------------------------------------

// bool not( real type )

template<>
GLM_API bool type_traits<float>::Not(const float& value)
{
    return isZero(value);
}

template<>
GLM_API bool type_traits<double>::Not(const double& value)
{
    return isZero(value);
}

template<>
GLM_API bool type_traits<long double>::Not(const long double& value)
{
    return isZero(value);
}

// bool equal ( real type )

template<>
GLM_API bool type_traits<float>::equal(const float& x, const float& y)
{
    return isZero(x - y);
}

template<>
GLM_API bool type_traits<double>::equal(const double& x, const double& y)
{
    return isZero(x - y);
}

template<>
GLM_API bool type_traits<long double>::equal(const long double& x, const long double& y)
{
    return isZero(x - y);
}

//------------------------------------------------------------------------------
// identity
//------------------------------------------------------------------------------

// vector
template<size_t N, typename T>
class type_traits<vec<N, T> >
{
public:
    GLM_CLASS_TYPEDEF(T);

public:
    static vec<N, T> identity()
    {
        return vec<N, T>();
    }
};

// matrix
template<size_t CX, size_t CY, typename T>
class type_traits<mat<CX, CY, T> >
{
public:
    GLM_CLASS_TYPEDEF(T);

public:
    static mat<CX, CY, T> identity()
    {
        return mat<CX, CY, T>(static_cast<T>(1));
    }
};

} // end namespace glm

#endif // GLM_TYPE_TRAITS_HPP_20211115202142
