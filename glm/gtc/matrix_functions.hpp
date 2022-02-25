/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 matrix_functions.hpp

 2022-02-25 16:07:19

*/
#ifndef GLM_MATRIX_FUNCTIONS_HPP_20220225160719
#define GLM_MATRIX_FUNCTIONS_HPP_20220225160719

#include <cassert>
#include "../matrix.hpp"



namespace glm {

template<size_t CY, size_t CX, typename T>
GLM_API typename mat<CY, CX, T>::row_type row(const mat<CY, CX, T>& m, length_t index)
{
    assert(index >= 0 && index < m[0].length());

    typename mat<CY, CX, T>::row_type Result(0);
    for(length_t i = 0; i < m.length(); ++i)
        Result[i] = m[i][index];
    return Result;
}

template<size_t CY, size_t CX, typename T>
GLM_API typename mat<CY, CX, T>::col_type column(const mat<CY, CX, T>& m, length_t index)
{
    assert(index >= 0 && index < m.length());

    return m[index];
}

//
// matrix
//

template<size_t CY, size_t CX, typename T>
GLM_API bool operator == (const mat<CY, CX, T>& x, const mat<CY, CX, T>& y)
{
    for (int i = 0; i < CY; ++i) {
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;
}

template<size_t CY, size_t CX, typename T>
GLM_API bool operator != (const mat<CY, CX, T>& x, const mat<CY, CX, T>& y)
{
    for (int i = 0; i < CY; ++i) {
        if (x[i] == y[i]) {
            return false;
        }
    }
    return true;
}

}// end namespace glm

#endif// GLM_MATRIX_FUNCTIONS_HPP_20220225160719
