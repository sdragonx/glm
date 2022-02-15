/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 vector.hpp

 2021-10-19 14:21:37

*/
#ifndef GLM_VECTOR_HPP_20211019142137
#define GLM_VECTOR_HPP_20211019142137

#include "detail/constants.hpp"



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
    length_t length()const
    {
        return ELEMENTS;
    }

    reference operator[](size_t i)
    {
        return m[i];
    }

    const_reference operator[](size_t i)const
    {
        return m[i];
    }

    pointer data()
    {
        return m;
    }

    const_pointer data()const
    {
        return m;
    }
};

}// end namespace glm

#endif// GLM_VECTOR_HPP_20211019142137
