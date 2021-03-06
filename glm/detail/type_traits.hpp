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

    static T identity()
    {
        return T();
    }

    // to boolean
    static bool judge(const T& value)
    {
        return value != T(0);
    }

    static bool isZero(const T& value)
    {
        return value == T(0);
    }

    static bool Not(const T& value)
    {
        return !value;
    }

    static bool less(const T& x, const T& y)
    {
        return x < y;
    }

    static bool lessEqual(const T& x, const T& y)
    {
        return x <= y;
    }

    static bool greater(const T& x, const T& y)
    {
        return x > y;
    }

    static bool greaterEqual(const T& x, const T& y)
    {
        return x >= y;
    }

    static bool equal(const T& x, const T& y)
    {
        return x == y;
    }

    static bool notEqual(const T& x, const T& y)
    {
        return !equal(x, y);
    }
};

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

//
// vector
//

template<size_t N, typename T>
class type_traits< vec<N, T> >
{
public:
    GLM_CLASS_TYPEDEF(T);

public:
    static vec<N, T> identity()
    {
        return vec<N, T>();
    }

};

//
// matrix
//

template<size_t CX, size_t CY, typename T>
class type_traits< mat<CX, CY, T> >
{
public:
    GLM_CLASS_TYPEDEF(T);

public:
    static mat<CX, CY, T> identity()
    {
        return mat<CX, CY, T>(static_cast<T>(1));
    }

};


}// end namespace glm

#endif// GLM_TYPE_TRAITS_HPP_20211115202142
