/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 vec.hpp

 2021-10-19 14:21:37

*/
#ifndef VEC_HPP_20211019142137
#define VEC_HPP_20211019142137

#include "detail/constants.hpp"

namespace cgl{
namespace glm{

template<length_t N, typename T>
class vec
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef vec this_type;

    enum { ELEMENTS = N };

public:
    value_type m[ELEMENTS];

public:
    length_t length()const { return ELEMENTS; }

    refrence operator[](size_t i) { return m[i]; }
    const_refrence operator[](size_t i)const { return m[i]; }

    pointer data() { return m; }
    const_pointer data()const { return m; }
};

}// end namespace glm
}// end namespace cgl

#endif// VEC_HPP_20211019142137
