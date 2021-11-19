/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 constants.hpp

 2021-11-13 22:10:26

*/
#ifndef CONSTANTS_HPP_20211113221026
#define CONSTANTS_HPP_20211113221026

#include "setup.hpp"

namespace cgl{
namespace glm{

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
const T constants<T>::epsilon = std::numeric_limits<T>::epsilon();

template<typename T>
const T constants<T>::pi = T(3.141592653589793238462);

template<typename T>
const T constants<T>::radians = T(0.017453292519943295769);

template<typename T>
const T constants<T>::inv_radians = T(57.295779513082320876798);



}// end namespace glm
}// end namespace cgl

#endif// CONSTANTS_HPP_20211113221026
