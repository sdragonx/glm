/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 mat3x2.hpp

 2022-05-20 18:08:09

*/
#ifndef GLM_MAT3X2_HPP20220520180809
#define GLM_MAT3X2_HPP20220520180809

#include "matrix.hpp"



namespace glm {

//
// class mat<3, 2, T>
//

template<typename T>
class mat<3, 2, T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef mat<3, 2, T> this_type;
    typedef vec<2, T> col_type;
    typedef vec<3, T> row_type;
    typedef mat<2, 3, T> transpose_type;

    enum {
        COLS = 2, 
        ROWS = 3, 
        ELEMENTS = 6, 
    };

public:
    col_type m[ROWS];

public:
    mat()
    {
    }

    mat(value_type scalar)
    {
        const T zero = constants<T>::zero; 
        m[0] = col_type(scalar, zero);
        m[1] = col_type(zero, scalar);
        m[2] = col_type(zero, zero);
    }

    mat(const col_type& v0, const col_type& v1, const col_type& v2)
    {
        m[0] = v0;
        m[1] = v1;
        m[2] = v2;
    }

    mat(value_type m00, value_type m01,
        value_type m10, value_type m11,
        value_type m20, value_type m21)
    {
        m[0] = col_type(m00, m01);
        m[1] = col_type(m10, m11);
        m[2] = col_type(m20, m21);
    }

    mat(const mat<2, 2, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = col_type(zero, zero);
    }

    mat(const mat<2, 3, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = col_type(zero, zero);
    }

    mat(const mat<2, 4, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = col_type(zero, zero);
    }

    mat(const mat<3, 2, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
    }

    mat(const mat<3, 3, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
    }

    mat(const mat<3, 4, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
    }

    mat(const mat<4, 2, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
    }

    mat(const mat<4, 3, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
    }

    mat(const mat<4, 4, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
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

    this_type& operator*=(const this_type& other);

};

//
// functions
//

// mat2 = mul( in mat3x2, in mat2x3 )
template<typename T>
GLM_API mat<2, 2, T> mat3x2_mul(const mat<3, 2, T>& m1, const mat<2, 3, T>& m2)
{
    mat<2, 2, T> product;

    product[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2];
    product[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2];
    product[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2];
    product[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2];

    return product;
}

// mat3x2 = mul( in mat3x2, in mat3 )
template<typename T>
GLM_API mat<3, 2, T> mat3x2_mul(const mat<3, 2, T>& m1, const mat<3, 3, T>& m2)
{
    mat<3, 2, T> product;

    product[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2];
    product[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2];
    product[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2];
    product[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2];
    product[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2];
    product[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2];

    return product;
}

// mat4x2 = mul( in mat3x2, in mat4x3 )
template<typename T>
GLM_API mat<4, 2, T> mat3x2_mul(const mat<3, 2, T>& m1, const mat<4, 3, T>& m2)
{
    mat<4, 2, T> product;

    product[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2];
    product[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2];
    product[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2];
    product[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2];
    product[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2];
    product[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2];
    product[3][0] = m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2];
    product[3][1] = m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2];

    return product;
}

// mat2x3 = transpose( in mat3x2 )
template<typename T>
GLM_API mat<2, 3, T> transpose(const mat<3, 2, T>& m)
{
     return mat2x3(
        m[0][0], m[1][0], m[2][0],
        m[0][1], m[1][1], m[2][1]);
}

// vec3 = transform( in vec2, in mat3x2 )
template<typename T>
GLM_API vec<3, T> transform(const vec<2, T>& v, const mat<3, 2, T>& m)
{
    return vec<3, T>(
        v[0] * m[0][0] + v[1] * m[0][1],
        v[0] * m[1][0] + v[1] * m[1][1],
        v[0] * m[2][0] + v[1] * m[2][1]);
}

// vec2 = transform ( in mat3x2, in vec3 )
template<typename T>
GLM_API vec<2, T> transform(const mat<3, 2, T>& m, const vec<3, T>& v)
{
    return vec<2, T>(
        m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2],
        m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2]);
}

//
// operators
//

// mat3x2 = mat3x2 + scalar
template<typename T>
GLM_API mat<3, 2, T> operator+(const mat<3, 2, T>& m, T scalar)
{
    return mat<3, 2, T>(m[0] + scalar, m[1] + scalar, m[2] + scalar);
}

// mat3x2 = mat3x2 - scalar
template<typename T>
GLM_API mat<3, 2, T> operator-(const mat<3, 2, T>& m, T scalar)
{
    return mat<3, 2, T>(m[0] - scalar, m[1] - scalar, m[2] - scalar);
}

// mat3x2 = mat3x2 * scalar
template<typename T>
GLM_API mat<3, 2, T> operator*(const mat<3, 2, T>& m, T scalar)
{
    return mat<3, 2, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar);
}

// mat3x2 = mat3x2 / scalar
template<typename T>
GLM_API mat<3, 2, T> operator/(const mat<3, 2, T>& m, T scalar)
{
    return mat<3, 2, T>(m[0] / scalar, m[1] / scalar, m[2] / scalar);
}

// mat3x2 = scalar + mat3x2
template<typename T>
GLM_API mat<3, 2, T> operator+(T scalar, const mat<3, 2, T>& m)
{
    return mat<3, 2, T>(scalar + m[0], scalar + m[1], scalar + m[2]);
}

// mat3x2 = scalar - mat3x2
template<typename T>
GLM_API mat<3, 2, T> operator-(T scalar, const mat<3, 2, T>& m)
{
    return mat<3, 2, T>(scalar - m[0], scalar - m[1], scalar - m[2]);
}

// mat3x2 = scalar * mat3x2
template<typename T>
GLM_API mat<3, 2, T> operator*(T scalar, const mat<3, 2, T>& m)
{
    return mat<3, 2, T>(scalar * m[0], scalar * m[1], scalar * m[2]);
}

// mat3x2 = scalar / mat3x2
template<typename T>
GLM_API mat<3, 2, T> operator/(T scalar, const mat<3, 2, T>& m)
{
    return mat<3, 2, T>(scalar / m[0], scalar / m[1], scalar / m[2]);
}

// mat2 = mat3x2 x mat2x3
template<typename T>
GLM_API mat<2, 2, T> operator*(const mat<3, 2, T>& m1, const mat<2, 3, T>& m2)
{
    return mat3x2_mul(m1, m2);
}

// mat3x2 = mat3x2 x mat3
template<typename T>
GLM_API mat<3, 2, T> operator*(const mat<3, 2, T>& m1, const mat<3, 3, T>& m2)
{
    return mat3x2_mul(m1, m2);
}

// mat4x2 = mat3x2 x mat4x3
template<typename T>
GLM_API mat<4, 2, T> operator*(const mat<3, 2, T>& m1, const mat<4, 3, T>& m2)
{
    return mat3x2_mul(m1, m2);
}

// mat3x2 *= mat3x2
template<typename T>
GLM_API mat<3, 2, T>& mat<3, 2, T>::operator*=(const mat<3, 2, T>& other)
{
    *this = mat3x2_mul(*this, other);
    return *this;
}

// vec3 = vec2 x mat3x2
template<typename T>
GLM_API vec<3, T> operator*(const vec<2, T>& v, const mat<3, 2, T>& m)
{
    return transform(v, m);
}

// vec2 = mat3x2 x vec3
template<typename T>
GLM_API vec<2, T> operator*(const mat<3, 2, T>& m, const vec<3, T>& v)
{
    return transform(m, v);
}

}// end namespace glm

#endif// GLM_MAT3X2_HPP20220520180809
