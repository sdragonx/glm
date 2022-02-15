/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 matrix_inverse.hpp

 2022-02-13 23:00:38

*/
#ifndef GLM_MATRIX_INVERSE_HPP_20220213230038
#define GLM_MATRIX_INVERSE_HPP_20220213230038

#include "matrix_determinant.hpp"



namespace glm {

//
// mat2 inverse( in mat2 )
//

template<typename T>
GLM_API mat<2, 2, T> inverse(const mat<2, 2, T>& m)
{
    T d = mat2_determinant(m);

    if (abs(d) < constants<T>::epsilon) {
        return m;
    }

    d = constants<T>::one / d;

    mat<2, 2, T> product;
    product[0][0] = + m[1][1] * d;
    product[0][1] = - m[0][1] * d;
    product[1][0] = - m[1][0] * d;
    product[1][1] = + m[0][0] * d;

    return product;
}


//
// mat3 inverse( in mat3 )
//

template<typename T>
GLM_API mat<3, 3, T> inverse(const mat<3, 3, T>& m)
{
    T d = determinant(m);

    if (abs(d) < constants<T>::epsilon) {
        return m;
    }

    d = constants<T>::one / d;

    mat<3, 3, T> product;
    product[0][0] = +(m[1][1] * m[2][2] - m[2][1] * m[1][2]) * d;
    product[0][1] = -(m[0][1] * m[2][2] - m[2][1] * m[0][2]) * d;
    product[0][2] = +(m[0][1] * m[1][2] - m[1][1] * m[0][2]) * d;
    product[1][0] = -(m[1][0] * m[2][2] - m[2][0] * m[1][2]) * d;
    product[1][1] = +(m[0][0] * m[2][2] - m[2][0] * m[0][2]) * d;
    product[1][2] = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]) * d;
    product[2][0] = +(m[1][0] * m[2][1] - m[2][0] * m[1][1]) * d;
    product[2][1] = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]) * d;
    product[2][2] = +(m[0][0] * m[1][1] - m[1][0] * m[0][1]) * d;

    return product;
}

//
// mat4 inverse( in mat4 )
//

template<typename T>
GLM_API mat<4, 4, T> inverse(const mat<4, 4, T>& m)
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

    // calculate the determinant.
    T d = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

    if (abs(d) < constants<T>::epsilon) {
        return m;
    }

    d = constants<T>::one / d;

    mat<4, 4, T> product;
    product[0][0] = (+ m[1][1] * b5 - m[1][2] * b4 + m[1][3] * b3) * d;
    product[0][1] = (- m[0][1] * b5 + m[0][2] * b4 - m[0][3] * b3) * d;
    product[0][2] = (+ m[3][1] * a5 - m[3][2] * a4 + m[3][3] * a3) * d;
    product[0][3] = (- m[2][1] * a5 + m[2][2] * a4 - m[2][3] * a3) * d;

    product[1][0] = (- m[1][0] * b5 + m[1][2] * b2 - m[1][3] * b1) * d;
    product[1][1] = (+ m[0][0] * b5 - m[0][2] * b2 + m[0][3] * b1) * d;
    product[1][2] = (- m[3][0] * a5 + m[3][2] * a2 - m[3][3] * a1) * d;
    product[1][3] = (+ m[2][0] * a5 - m[2][2] * a2 + m[2][3] * a1) * d;

    product[2][0] = (+ m[1][0] * b4 - m[1][1] * b2 + m[1][3] * b0) * d;
    product[2][1] = (- m[0][0] * b4 + m[0][1] * b2 - m[0][3] * b0) * d;
    product[2][2] = (+ m[3][0] * a4 - m[3][1] * a2 + m[3][3] * a0) * d;
    product[2][3] = (- m[2][0] * a4 + m[2][1] * a2 - m[2][3] * a0) * d;

    product[3][0] = (- m[1][0] * b3 + m[1][1] * b1 - m[1][2] * b0) * d;
    product[3][1] = (+ m[0][0] * b3 - m[0][1] * b1 + m[0][2] * b0) * d;
    product[3][2] = (- m[3][0] * a3 + m[3][1] * a1 - m[3][2] * a0) * d;
    product[3][3] = (+ m[2][0] * a3 - m[2][1] * a1 + m[2][2] * a0) * d;
    
    return product;
}


}// end namespace glm

#endif// GLM_MATRIX_INVERSE_HPP_20220213230038
