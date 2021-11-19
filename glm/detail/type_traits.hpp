/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 type_traits.hpp

 2021-11-15 20:21:42

*/
#ifndef GLM_TYPE_TRAITS_HPP_20211115202142
#define GLM_TYPE_TRAITS_HPP_20211115202142

#include "constants.hpp"

namespace cgl{
namespace glm{


template<typename genT, typename T>
class type_traits
{
public:
    GLM_CLASS_TYPEDEF(T);

    static genT identity()
    {
        return genT();
    }

};

//
// vector
//

template<size_t N, typename T>
class type_traits< vec<N, T>, T >
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
class type_traits< mat<CX, CY, T>, T >
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
}// end namespace cgl

#endif// GLM_TYPE_TRAITS_HPP_20211115202142
