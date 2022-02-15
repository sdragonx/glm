/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 matrix.hpp

 2020-10-27 02:05:52

*/
#ifndef GLM_MATRIX_HPP_20201027020552
#define GLM_MATRIX_HPP_20201027020552

#include "vector.hpp"



namespace glm{

//
// mat<X, Y, T>
//

template<length_t CX, length_t CY, typename T>
class mat
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef mat this_type;
    typedef vec<CX, T> row_type;

    enum{
        COLUMNS = CX,
        ROWS = CY,
        ELEMENTS = CX * CY,
    };

public:
    row_type m[ROWS];

public:
    length_t length()const
    {
        return ELEMENTS;
    }

    pointer data()
    {
        return &m[0][0];
    }

    const_pointer data()const
    {
        return &m[0][0];
    }

    row_type& operator[](size_t i)
    {
        return m[i];
    }

    const row_type& operator[](size_t i)const
    {
        return m[i];
    }

    reference operator()(size_t x, size_t y)
    {
        return m[y][x];
    }

    const_reference operator()(size_t x, size_t y)const
    {
        return m[y][x];
    }
};

}// end namespace glm

#endif// GLM_MATRIX_HPP_20201027020552
