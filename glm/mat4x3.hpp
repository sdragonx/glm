/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 mat4x3.hpp

 2022-05-20 18:08:09

*/
#ifndef GLM_MAT4X3_HPP20220520180809
#define GLM_MAT4X3_HPP20220520180809

#include "matrix.hpp"



namespace glm {

//
// class mat<4, 3, T>
//

template<typename T>
class mat<4, 3, T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef mat<4, 3, T> this_type;
    typedef vec<3, T> col_type;
    typedef vec<4, T> row_type;
    typedef mat<3, 4, T> transpose_type;

    enum {
        COLS = 3, 
        ROWS = 4, 
        ELEMENTS = 12, 
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
        m[0] = col_type(scalar, zero, zero);
        m[1] = col_type(zero, scalar, zero);
        m[2] = col_type(zero, zero, scalar);
        m[3] = col_type(zero, zero, zero);
    }

    mat(const col_type& v0, const col_type& v1, const col_type& v2, const col_type& v3)
    {
        m[0] = v0;
        m[1] = v1;
        m[2] = v2;
        m[3] = v3;
    }

    mat(value_type m00, value_type m01, value_type m02,
        value_type m10, value_type m11, value_type m12,
        value_type m20, value_type m21, value_type m22,
        value_type m30, value_type m31, value_type m32)
    {
        m[0] = col_type(m00, m01, m02);
        m[1] = col_type(m10, m11, m12);
        m[2] = col_type(m20, m21, m22);
        m[3] = col_type(m30, m31, m32);
    }

    mat(const mat<2, 2, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = col_type(other.m[0], zero);
        m[1] = col_type(other.m[1], zero);
        m[2] = col_type(zero, zero, one);
        m[3] = col_type(zero, zero, zero);
    }

    mat(const mat<2, 3, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = col_type(zero, zero, one);
        m[3] = col_type(zero, zero, zero);
    }

    mat(const mat<2, 4, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = col_type(zero, zero, one);
        m[3] = col_type(zero, zero, zero);
    }

    mat(const mat<3, 2, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = col_type(other.m[0], zero);
        m[1] = col_type(other.m[1], zero);
        m[2] = col_type(other.m[2], one);
        m[3] = col_type(zero, zero, zero);
    }

    mat(const mat<3, 3, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
        m[3] = col_type(zero, zero, zero);
    }

    mat(const mat<3, 4, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
        m[3] = col_type(zero, zero, zero);
    }

    mat(const mat<4, 2, T>& other)
    {
        const T zero = constants<T>::zero;
        const T one = constants<T>::one;
        m[0] = col_type(other.m[0], zero);
        m[1] = col_type(other.m[1], zero);
        m[2] = col_type(other.m[2], one);
        m[3] = col_type(other.m[3], zero);
    }

    mat(const mat<4, 3, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
        m[3] = other.m[3];
    }

    mat(const mat<4, 4, T>& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
        m[3] = other.m[3];
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

// mat2x3 = mul( in mat4x3, in mat2x4 )
template<typename T>
GLM_API mat<2, 3, T> mat4x3_mul(const mat<4, 3, T>& m1, const mat<2, 4, T>& m2)
{
    mat<2, 3, T> product;

    product[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3];
    product[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3];
    product[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3];
    product[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3];
    product[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3];
    product[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3];

    return product;
}

// mat3 = mul( in mat4x3, in mat3x4 )
template<typename T>
GLM_API mat<3, 3, T> mat4x3_mul(const mat<4, 3, T>& m1, const mat<3, 4, T>& m2)
{
    mat<3, 3, T> product;

    product[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3];
    product[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3];
    product[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3];
    product[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3];
    product[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3];
    product[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3];
    product[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3];
    product[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3];
    product[2][2] = m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3];

    return product;
}

// mat4x3 = mul( in mat4x3, in mat4 )
template<typename T>
GLM_API mat<4, 3, T> mat4x3_mul(const mat<4, 3, T>& m1, const mat<4, 4, T>& m2)
{
    mat<4, 3, T> product;

    product[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3];
    product[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3];
    product[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3];
    product[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3];
    product[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3];
    product[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3];
    product[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3];
    product[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3];
    product[2][2] = m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3];
    product[3][0] = m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2] + m1[3][0] * m2[3][3];
    product[3][1] = m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2] + m1[3][1] * m2[3][3];
    product[3][2] = m1[0][2] * m2[3][0] + m1[1][2] * m2[3][1] + m1[2][2] * m2[3][2] + m1[3][2] * m2[3][3];

    return product;
}

// mat3x4 = transpose( in mat4x3 )
template<typename T>
GLM_API mat<3, 4, T> transpose(const mat<4, 3, T>& m)
{
     return mat3x4(
        m[0][0], m[1][0], m[2][0], m[3][0],
        m[0][1], m[1][1], m[2][1], m[3][1],
        m[0][2], m[1][2], m[2][2], m[3][2]);
}

// vec4 = transform( in vec3, in mat4x3 )
template<typename T>
GLM_API vec<4, T> transform(const vec<3, T>& v, const mat<4, 3, T>& m)
{
    return vec<4, T>(
        v[0] * m[0][0] + v[1] * m[0][1] + v[2] * m[0][2],
        v[0] * m[1][0] + v[1] * m[1][1] + v[2] * m[1][2],
        v[0] * m[2][0] + v[1] * m[2][1] + v[2] * m[2][2],
        v[0] * m[3][0] + v[1] * m[3][1] + v[2] * m[3][2]);
}

// vec3 = transform ( in mat4x3, in vec4 )
template<typename T>
GLM_API vec<3, T> transform(const mat<4, 3, T>& m, const vec<4, T>& v)
{
    return vec<3, T>(
        m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3],
        m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3],
        m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3]);
}

//
// operators
//

// mat4x3 = mat4x3 + scalar
template<typename T>
GLM_API mat<4, 3, T> operator+(const mat<4, 3, T>& m, T scalar)
{
    return mat<4, 3, T>(m[0] + scalar, m[1] + scalar, m[2] + scalar, m[3] + scalar);
}

// mat4x3 = mat4x3 - scalar
template<typename T>
GLM_API mat<4, 3, T> operator-(const mat<4, 3, T>& m, T scalar)
{
    return mat<4, 3, T>(m[0] - scalar, m[1] - scalar, m[2] - scalar, m[3] - scalar);
}

// mat4x3 = mat4x3 * scalar
template<typename T>
GLM_API mat<4, 3, T> operator*(const mat<4, 3, T>& m, T scalar)
{
    return mat<4, 3, T>(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar);
}

// mat4x3 = mat4x3 / scalar
template<typename T>
GLM_API mat<4, 3, T> operator/(const mat<4, 3, T>& m, T scalar)
{
    return mat<4, 3, T>(m[0] / scalar, m[1] / scalar, m[2] / scalar, m[3] / scalar);
}

// mat4x3 = scalar + mat4x3
template<typename T>
GLM_API mat<4, 3, T> operator+(T scalar, const mat<4, 3, T>& m)
{
    return mat<4, 3, T>(scalar + m[0], scalar + m[1], scalar + m[2], scalar + m[3]);
}

// mat4x3 = scalar - mat4x3
template<typename T>
GLM_API mat<4, 3, T> operator-(T scalar, const mat<4, 3, T>& m)
{
    return mat<4, 3, T>(scalar - m[0], scalar - m[1], scalar - m[2], scalar - m[3]);
}

// mat4x3 = scalar * mat4x3
template<typename T>
GLM_API mat<4, 3, T> operator*(T scalar, const mat<4, 3, T>& m)
{
    return mat<4, 3, T>(scalar * m[0], scalar * m[1], scalar * m[2], scalar * m[3]);
}

// mat4x3 = scalar / mat4x3
template<typename T>
GLM_API mat<4, 3, T> operator/(T scalar, const mat<4, 3, T>& m)
{
    return mat<4, 3, T>(scalar / m[0], scalar / m[1], scalar / m[2], scalar / m[3]);
}

// mat2x3 = mat4x3 x mat2x4
template<typename T>
GLM_API mat<2, 3, T> operator*(const mat<4, 3, T>& m1, const mat<2, 4, T>& m2)
{
    return mat4x3_mul(m1, m2);
}

// mat3 = mat4x3 x mat3x4
template<typename T>
GLM_API mat<3, 3, T> operator*(const mat<4, 3, T>& m1, const mat<3, 4, T>& m2)
{
    return mat4x3_mul(m1, m2);
}

// mat4x3 = mat4x3 x mat4
template<typename T>
GLM_API mat<4, 3, T> operator*(const mat<4, 3, T>& m1, const mat<4, 4, T>& m2)
{
    return mat4x3_mul(m1, m2);
}

// mat4x3 *= mat4x3
template<typename T>
GLM_API mat<4, 3, T>& mat<4, 3, T>::operator*=(const mat<4, 3, T>& other)
{
    *this = mat4x3_mul(*this, other);
    return *this;
}

// vec4 = vec3 x mat4x3
template<typename T>
GLM_API vec<4, T> operator*(const vec<3, T>& v, const mat<4, 3, T>& m)
{
    return transform(v, m);
}

// vec3 = mat4x3 x vec4
template<typename T>
GLM_API vec<3, T> operator*(const mat<4, 3, T>& m, const vec<4, T>& v)
{
    return transform(m, v);
}

}// end namespace glm

#endif// GLM_MAT4X3_HPP20220520180809
