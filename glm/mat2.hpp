/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 mat2.hpp

 2020-03-31 13:14:12

*/
#ifndef GLM_MAT2_HPP_20200331131412
#define GLM_MAT2_HPP_20200331131412

#include "mat.hpp"
#include "gtc/matrix_transform.hpp"



namespace glm{


//
// void mat2x3_add( in mat2x3, in T, out mat2x3 )
//

template<typename T>
inline void mat2x3_add(const T* m, T scalar, T* dest)
{
    dest[0]  = m[0]  + scalar;
    dest[1]  = m[1]  + scalar;
    dest[2]  = m[2]  + scalar;
    dest[3]  = m[3]  + scalar;
    dest[4]  = m[4]  + scalar;
    dest[5]  = m[5]  + scalar;
}

//
// void mat2x3_add( in mat2x3, in mat2x3, out mat2x3 )
//

template<typename T>
inline void mat2x3_add(const T* m1, const T* m2, T* dest)
{
    dest[0]  = m1[0]  + m2[0];
    dest[1]  = m1[1]  + m2[1];
    dest[2]  = m1[2]  + m2[2];
    dest[3]  = m1[3]  + m2[3];
    dest[4]  = m1[4]  + m2[4];
    dest[5]  = m1[5]  + m2[5];
}

//
// void mat2x3_sub( in mat2x3, in mat2x3, out mat2x3 )
//

template<typename T>
inline void mat2x3_sub(const T* m1, const T* m2, T* dest)
{
    dest[0]  = m1[0]  - m2[0];
    dest[1]  = m1[1]  - m2[1];
    dest[2]  = m1[2]  - m2[2];
    dest[3]  = m1[3]  - m2[3];
    dest[4]  = m1[4]  - m2[4];
    dest[5]  = m1[5]  - m2[5];
}

//
// void mat2x3_mul( in mat2x3, in T, out mat2x3 )
//

template<typename T>
inline void mat2x3_mul(const T* m, T scalar, T* dest)
{
    dest[0]  = m[0]  * scalar;
    dest[1]  = m[1]  * scalar;
    dest[2]  = m[2]  * scalar;
    dest[3]  = m[3]  * scalar;
    dest[4]  = m[4]  * scalar;
    dest[5]  = m[5]  * scalar;
}

//
// void mat2x3_mul( in mat2x3, in mat2x3, out mat2x3 )
//

template<typename T>
GLM_API void mat2x3_mul(const T* m1, const T* m2, T* dest)
{
    T product[6];

    product[0] = m1[0] * m2[0] + m1[1] * m2[2];
    product[1] = m1[0] * m2[1] + m1[1] * m2[3];

    product[2] = m1[2] * m2[0] + m1[3] * m2[2];
    product[3] = m1[2] * m2[1] + m1[3] * m2[3];

    product[4] = m1[4] * m2[0] + m1[5] * m2[2] + m2[4];
    product[5] = m1[4] * m2[1] + m1[5] * m2[3] + m2[5];

    memcpy(dest, product, sizeof(product));
}

//
// bool mat2x3_determinant( in mat2x3, out T )
//
template<typename T>
bool mat2x3_determinant(const T* m, T& d)
{
    d = m[0] * m[3] - m[1] * m[2];

    if (abs(d) < constants<T>::epsilon) {
        return false;
    }

    d = constants<T>::one / d;

    return true;
}

//
// bool mat2x3_inverse( in mat2x3, out mat2x3 )
//

template<typename T>
bool mat2x3_inverse(const T* m, T* dest)
{
    T product[6];
    T d;

    if (mat2x3_determinant(m, d) == false) {
        return false;
    }

    product[0] =  m[3] * d;
    product[1] = -m[1] * d;
    product[2] = -m[2] * d;
    product[3] =  m[0] * d;
    product[4] = -m[4] * product[0] - m[5] * product[2];
    product[5] = -m[4] * product[1] - m[5] * product[3];

    memcpy(dest, product, sizeof(product));

    return true;
}

//
// void mat2x3_transform( in mat2x3, in vec2, out vec2 )
//

template<typename T>
GLM_API void mat2x3_transform(const T* m, const T* v, T* dest)
{
    T product[2];

    product[0] = m[0] * v[0] + m[2] * v[1] + m[4];
    product[1] = m[1] * v[0] + m[3] * v[1] + m[5];

    memcpy(dest, product, sizeof(product));
}

//
// mat2x3
//

template<typename T>
class mat<2, 3, T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef mat<2, 3, T> this_type;
    typedef vec<2, T> row_type;

    enum{
        COLS = 2,
        ROWS = 3,
        ELEMENTS = 6
    };

public:
    row_type m[3];

public:
    mat()
    {
    }

    mat(value_type scalar)
    {
        const T zero = constants<T>::zero;
        m[0] = vec<2, T>(scalar, zero);
        m[1] = vec<2, T>(zero, scalar);
        m[2] = vec<2, T>(zero, zero);
    }

    mat(const row_type& a, const row_type& b, const row_type& c)
    {
        m[0] = a;
        m[1] = b;
        m[2] = c;
    }

    mat(
        value_type m00, value_type m01,
        value_type m10, value_type m11,
        value_type m20, value_type m21)
    {
        m[0] = row_type(m00, m01);
        m[1] = row_type(m10, m11);
        m[2] = row_type(m20, m21);
    }

    mat(const this_type& m)
    {
        memcpy(data(), m.data(), sizeof(value_type) * ELEMENTS);
    }

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

    //
    // ext
    //

    this_type& translate(value_type x, value_type y)
    {
        m[2][0] += x;
        m[2][1] += y;
        return *this;
    }

    this_type& scale(value_type x)
    {
        return this->scale(x, x);
    }

    this_type& scale(value_type x, value_type y)
    {
        m[0][0] *= x; m[0][1] *= y;
        m[1][0] *= x; m[1][1] *= y;
        m[2][0] *= x; m[2][1] *= y;

        return *this;
    }

    this_type& rotate(value_type angle)
    {
        const value_type zero = constants<T>::zero;
        value_type cosine = cos(angle);
        value_type sine   = sin(angle);

        value_type mat[6] = {
            cosine, sine, 
            -sine, cosine, 
            zero, zero
        };

        mat2x3_mul(data(), mat, data());

        return *this;
    }
};

//
// operator
//

template<typename T>
GLM_API mat<2, 3, T> operator +(const mat<2, 3, T>& m, T n)
{
    mat<2, 3, T> product;
    mat2x3_add(m.data(), n, product.data());
    return product;
}

template<typename T>
GLM_API mat<2, 3, T> operator +(const mat<2, 3, T>& m1, const mat<2, 3, T>& m2)
{
    mat<2, 3, T> product;
    mat2x3_add(m1.data(), m2.data(), product.data());
    return product;
}

template<typename T>
GLM_API mat<2, 3, T> operator -(const mat<2, 3, T>& m, T n)
{
    mat<2, 3, T> product;
    mat2x3_mul(m.data(), -n, product.data());
    return product;
}

template<typename T>
GLM_API mat<2, 3, T> operator -(const mat<2, 3, T>& m1, const mat<2, 3, T>& m2)
{
    mat<2, 3, T> product;
    mat2x3_sub(m1.data(), m2.data(), product.data());
    return product;
}

template<typename T>
GLM_API mat<2, 3, T> operator *(const mat<2, 3, T>& m, T n)
{
    mat<2, 3, T> product;
    mat2x3_mul(m.data(), n, product.data());
    return product;
}

template<typename T>
GLM_API mat<2, 3, T> operator *(const mat<2, 3, T>& m1, const mat<2, 3, T>& m2)
{
    mat<2, 3, T> product;
    mat2x3_mul(m1.data(), m2.data(), product.data());
    return product;
}

template<typename T>
GLM_API mat<2, 3, T> operator /(const mat<2, 3, T>& m, T n)
{
    mat<2, 3, T> product;
    mat2x3_mul(m.data(), constants<T>::one / n, product.data());
    return product;
}

// transform
template<typename T>
GLM_API vec<2, T> operator *(const mat<2, 3, T>& m, const vec<2, T>& v)
{
    vec<2, T> product;
    mat2x3_transform(m.data(), v.data(), product.data());
    return product;
}

//
// mat2x3 transpose( in mat2x3 )
//

template<typename T>
GLM_API mat<2, 3, T> transpose(const mat<2, 3, T>& m)
{
    mat<2, 3, T> product;
    mat2x3_transpose_copy(m.data(), product.data());
    return product;
}

//
// mat2x3 inverse( in mat2x3 )
//

template<typename T>
GLM_API mat<2, 3, T> inverse(const mat<2, 3, T>& m)
{
    mat<2, 3, T> product;
    mat2x3_inverse(m.data(), product.data());
    return product;
}



//
// extension
//

template<typename T>
GLM_API mat<2, 3, T> rotate2x3(T angle)
{
    T cosine = cos(angle);
    T sine = sin(angle);
    return mat<2, 3, T>(cosine, -sine, sine, cosine, constants<T>::zero, constants<T>::zero);
}

template<typename T>
GLM_API mat<2, 3, T> translate(const mat<2, 3, T>& m, const vec<2, T>& v)
{
    return mat<2, 3, T>(m[0], m[1], m[2] + v);
}

template<typename T>
GLM_API mat<2, 3, T> rotate(const mat<2, 3, T>& m, T angle)
{
    mat<2, 3, T> product;

    mat2x3_mul(m.data(), rotate2x3(angle).data(), product.data());

    return product;
}

template<typename T>
GLM_API mat<2, 3, T> scale(const mat<2, 3, T>& m, const vec<2, T>& v)
{
    return mat<2, 3, T>(m[0] * v, m[1] * v, m[2] * v);
}

}// end namespace glm

#endif// GLM_MAT2_HPP_20200331131412

/*

void ortho(Transform3x2 dst, float l, float r, float b, float t)
{
  dst[0][0] = 2/(r-l);
  dst[0][1] = 0;
  dst[0][2] = -(r+l)/(r-l);
  dst[1][0] = 0;
  dst[1][1] = 2/(t-b);
  dst[1][2] = -(t+b)/(t-b);
}

void inverse_ortho(Transform3x2 dst, float l, float r, float b, float t)
{
  dst[0][0] = (r-l)/2;
  dst[0][1] = 0;
  dst[0][2] = (r+l)/2;
  dst[1][0] = 0;
  dst[1][1] = (t-b)/2;
  dst[1][2] = (t+b)/2;
}

*/