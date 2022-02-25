/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 constants.hpp

 2021-11-13 22:10:26

*/
#ifndef GLM_CONSTANTS_HPP_20211113221026
#define GLM_CONSTANTS_HPP_20211113221026

#include "float.hpp"



namespace glm {

//
// class constants
//

template<typename T>
class constants
{
public:
    GLM_CLASS_TYPEDEF(T);

    const static T zero;
    const static T half;
    const static T one;
    const static T two;

    const static T epsilon;

    const static T pi;
    const static T radians;
    const static T inv_radians;
};



template<typename T>
const T constants<T>::zero = T(0);

template<typename T>
const T constants<T>::half = T(0.5);

template<typename T>
const T constants<T>::one = T(1);

template<typename T>
const T constants<T>::two = T(2);

template<typename T>
const T constants<T>::epsilon = T(std::numeric_limits<T>::epsilon());

template<typename T>
const T constants<T>::pi = T(3.141592653589793238462);

template<typename T>
const T constants<T>::radians = T(0.017453292519943295769);

template<typename T>
const T constants<T>::inv_radians = T(57.295779513082320876798);

//
// functions
//

template<typename T>
inline T zero()
{
    return constants<T>::zero;
}

template<typename T>
inline T half()
{
    return constants<T>::half;
}

template<typename T>
inline T one()
{
    return constants<T>::one;
}

template<typename T>
inline T two()
{
    return constants<T>::two;
}

template<typename T>
inline T pi()
{
    return constants<T>::pi;
}

template<typename T>
inline T half_pi()
{
    return constants<T>::pi * constants<T>::half;
}

template<typename T>
inline T epsilon()
{
    return constants<T>::epsilon;
}

template<typename T>
inline T cos_one_over_two()
{
    return T(0.877582561890372716130286068203503191);
}

}// end namespace glm

#endif// GLM_CONSTANTS_HPP_20211113221026
