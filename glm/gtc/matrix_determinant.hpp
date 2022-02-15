/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 glm.matrix_determinant.hpp

 2022-02-13 23:01:45

*/
#ifndef GLM_MATRIX_DETERMINANT_HPP_20220213230145
#define GLM_MATRIX_DETERMINANT_HPP_20220213230145

#include "../matrix.hpp"



namespace glm {

//
// bool mat2_determinant( in mat2, out T )
//

template<typename T>
T determinant(const mat<2, 2, T>& m)
{
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

//
// bool mat3_determinant( in mat3, out T )
//

template<typename T>
GLM_API T determinant(const mat<3, 3, T>& m)
{
    return
        + m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
        - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
        + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
}

//
// bool mat4_determinant( in mat4, out T )
//

template<typename T>
GLM_API T determinant(const mat<4, 4, T>& m)
{
    T a0 = m[0][0] * m[1][1] - m[0][1] * m[1][0];
    T a1 = m[0][0] * m[1][2] - m[0][2] * m[1][0];
    T a2 = m[0][0] * m[1][3] - m[0][3] * m[1][0];
    T a3 = m[0][1] * m[1][2] - m[0][2] * m[1][1];
    T a4 = m[0][1] * m[1][3] - m[0][3] * m[1][1];
    T a5 = m[0][2] * m[1][3] - m[0][3] * m[1][2];
    T b0 = m[2][0] * m[3][1] - m[2][1] * m[3][0];
    T b1 = m[2][0] * m[3][2] - m[2][2] * m[3][0];
    T b2 = m[2][0] * m[3][3] - m[2][3] * m[3][0];
    T b3 = m[2][1] * m[3][2] - m[2][2] * m[3][1];
    T b4 = m[2][1] * m[3][3] - m[2][3] * m[3][1];
    T b5 = m[2][2] * m[3][3] - m[2][3] * m[3][2];

    return a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
}

}// end namespace glm

#endif// GLM_MATRIX_DETERMINANT_HPP_20220213230145
