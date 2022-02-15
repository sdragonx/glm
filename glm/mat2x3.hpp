/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 mat2x3.hpp

 2022-02-15 15:29:35

*/
#ifndef GLM_MAT2X3_HPP20220215152935
#define GLM_MAT2X3_HPP20220215152935

#include "matrix.hpp"



namespace glm {

//
// class mat<2, 3, T>
//

template<typename T>
class mat<2, 3, T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef mat<2, 3, T> this_type;
    typedef vec<3, T> col_type;
    typedef vec<2, T> row_type;

    enum {
        ROWS = 2, 
        COLS = 3, 
        ELEMENTS = 6, 
    };

public:
    col_type m[COLS];

public:
    mat()
    {
    }

    mat(value_type scalar)
    {
        const T zero = constants<T>::zero; 
        m[0] = col_type(scalar, zero, zero);
        m[1] = col_type(zero, scalar, zero);
    }

    mat(const col_type& v0, const col_type& v1)
    {
        m[0] = v0;
        m[1] = v1;
    }

    mat(value_type m00, value_type m01, value_type m02,
        value_type m10, value_type m11, value_type m12)
    {
        m[0] = col_type(m00, m01, m02);
        m[1] = col_type(m10, m11, m12);
    }

    mat(const mat<2, 2, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = col_type(other.m[0], zero);
        m[1] = col_type(other.m[1], zero);
    }

    mat(const mat<2, 3, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
    }

    mat(const mat<2, 4, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
    }

    mat(const mat<3, 2, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = col_type(other.m[0], zero);
        m[1] = col_type(other.m[1], zero);
    }

    mat(const mat<3, 3, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
    }

    mat(const mat<3, 4, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
    }

    mat(const mat<4, 2, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = col_type(other.m[0], zero);
        m[1] = col_type(other.m[1], zero);
    }

    mat(const mat<4, 3, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
    }

    mat(const mat<4, 4, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
    }

    length_t length()const
    {
        return COLS;
    }

    size_t elements()const
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

    col_type& operator[](size_t i)
    {
        return m[i];
    }

    const col_type& operator[](size_t i)const
    {
        return m[i];
    }
};

//
// functions
//

// mat2x3 = mul( in mat2x3, in mat2 )
template<typename T>
GLM_API mat<2, 3, T> mat2x3_mul(const mat<2, 3, T>& m1, const mat<2, 2, T>& m2)
{
    mat<2, 3, T> product;

    product[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1];
    product[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1];
    product[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1];
    product[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1];
    product[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1];
    product[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1];

    return product;
}

// mat3 = mul( in mat2x3, in mat3x2 )
template<typename T>
GLM_API mat<3, 3, T> mat2x3_mul(const mat<2, 3, T>& m1, const mat<3, 2, T>& m2)
{
    mat<3, 3, T> product;

    product[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1];
    product[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1];
    product[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1];
    product[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1];
    product[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1];
    product[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1];
    product[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1];
    product[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1];
    product[2][2] = m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1];

    return product;
}

// mat4x3 = mul( in mat2x3, in mat4x2 )
template<typename T>
GLM_API mat<4, 3, T> mat2x3_mul(const mat<2, 3, T>& m1, const mat<4, 2, T>& m2)
{
    mat<4, 3, T> product;

    product[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1];
    product[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1];
    product[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1];
    product[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1];
    product[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1];
    product[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1];
    product[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1];
    product[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1];
    product[2][2] = m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1];
    product[3][0] = m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1];
    product[3][1] = m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1];
    product[3][2] = m1[0][2] * m2[3][0] + m1[1][2] * m2[3][1];

    return product;
}

// mat3x2 = transpose( in mat2x3 )
template<typename T>
GLM_API mat<3, 2, T> transpose(const mat<2, 3, T>& m)
{
     return mat3x2(
        m[0][0], m[1][0], m[2][0],
        m[0][1], m[1][1], m[2][1]);
}

// vec3 = transform( in vec3, in mat2x3 )
template<typename T>
GLM_API vec<3, T> transform(const vec<3, T>& v, const mat<2, 3, T>& m)
{
    return vec<2, T>(
        v[0] * m[0][0] + v[1] * m[0][1] + v[2] * m[0][2],
        v[0] * m[1][0] + v[1] * m[1][1] + v[2] * m[1][2]);
}

// vec2 = transform ( in mat2x3, in vec2 )
template<typename T>
GLM_API vec<2, T> transform(const mat<2, 3, T>& m, const vec<2, T>& v)
{
    return vec<2, T>(
        m[0][0] * v[0] + m[1][0] * v[1],
        m[0][1] * v[0] + m[1][1] * v[1],
        m[0][2] * v[0] + m[1][2] * v[1]);
}

//
// operators
//

// mat2x3 = mat2x3 + scalar
template<typename T>
GLM_API mat<2, 3, T> operator+(const mat<2, 3, T>& m, T scalar)
{
    return mat<2, 3, T>(m[0] + scalar, m[1] + scalar);
}

// mat2x3 = mat2x3 - scalar
template<typename T>
GLM_API mat<2, 3, T> operator-(const mat<2, 3, T>& m, T scalar)
{
    return mat<2, 3, T>(m[0] - scalar, m[1] - scalar);
}

// mat2x3 = mat2x3 * scalar
template<typename T>
GLM_API mat<2, 3, T> operator*(const mat<2, 3, T>& m, T scalar)
{
    return mat<2, 3, T>(m[0] * scalar, m[1] * scalar);
}

// mat2x3 = mat2x3 / scalar
template<typename T>
GLM_API mat<2, 3, T> operator/(const mat<2, 3, T>& m, T scalar)
{
    return mat<2, 3, T>(m[0] / scalar, m[1] / scalar);
}

// mat2x3 = scalar + mat2x3
template<typename T>
GLM_API mat<2, 3, T> operator+(T scalar, const mat<2, 3, T>& m)
{
    return mat<2, 3, T>(scalar + m[0], scalar + m[1]);
}

// mat2x3 = scalar - mat2x3
template<typename T>
GLM_API mat<2, 3, T> operator-(T scalar, const mat<2, 3, T>& m)
{
    return mat<2, 3, T>(scalar - m[0], scalar - m[1]);
}

// mat2x3 = scalar * mat2x3
template<typename T>
GLM_API mat<2, 3, T> operator*(T scalar, const mat<2, 3, T>& m)
{
    return mat<2, 3, T>(scalar * m[0], scalar * m[1]);
}

// mat2x3 = scalar / mat2x3
template<typename T>
GLM_API mat<2, 3, T> operator/(T scalar, const mat<2, 3, T>& m)
{
    return mat<2, 3, T>(scalar / m[0], scalar / m[1]);
}

// mat2x3 = mat2x3 x mat2
template<typename T>
GLM_API mat<2, 3, T> operator*(const mat<2, 3, T>& m1, const mat<2, 2, T>& m2)
{
    return mat2x3_mul(m1, m2);
}

// mat3 = mat2x3 x mat3x2
template<typename T>
GLM_API mat<3, 3, T> operator*(const mat<2, 3, T>& m1, const mat<3, 2, T>& m2)
{
    return mat2x3_mul(m1, m2);
}

// mat4x3 = mat2x3 x mat4x2
template<typename T>
GLM_API mat<4, 3, T> operator*(const mat<2, 3, T>& m1, const mat<4, 2, T>& m2)
{
    return mat2x3_mul(m1, m2);
}

// vec3 = vec3 x mat2x3
template<typename T>
GLM_API vec<3, T> operator*(const vec<3, T>& v, const mat<2, 3, T>& m)
{
    return transform(v, m);
}

// vec2 = mat2x3 x vec2
template<typename T>
GLM_API vec<2, T> operator*(const mat<2, 3, T>& v, const vec<2, T>& m)
{
    return transform(m, v);
}

}// end namespace glm

#endif// GLM_MAT2X3_HPP20220215152935
