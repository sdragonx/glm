/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 vec2.hpp

 2021-10-19 15:41:30

*/
#ifndef GLM_VEC2_HPP_20211019154130
#define GLM_VEC2_HPP_20211019154130

#include "vector.hpp"



namespace glm{

#define GLM_VEC2_OPERATION(op)\
    template<typename X>\
    this_type operator op(const X& value)const\
    {\
        return this_type(x op value, y op value);\
    }\
    template<typename X>\
    this_type operator op(const vec<2, X>& v)const\
    {\
        return this_type(x op v.x, y op v.y);\
    }\
    template<typename X>\
    this_type operator op(const vec<3, X>& v)const\
    {\
        return this_type(x op v.x, y op v.y);\
    }\
    template<typename X>\
    this_type operator op(const vec<4, X>& v)const\
    {\
        return this_type(x op v.x, y op v.y);\
    }\
    template<typename X>\
    this_type& operator op##=(const X& value)\
    {\
        x op##= value; y op##= value;\
        return *this;\
    }\
    template<typename X>\
    this_type& operator op##=(const vec<2, X>& v)\
    {\
        x op##= v.x; y op##= v.y;\
        return *this;\
    }\
    template<typename X>\
    this_type& operator op##=(const vec<3, X>& v)\
    {\
        x op##= v.x; y op##= v.y;\
        return *this;\
    }\
    template<typename X>\
    this_type& operator op##=(const vec<4, X>& v)\
    {\
        x op##= v.x; y op##= v.y;\
        return *this;\
    }

#define GLM_VEC2_OPERATOR_COMMON(op)\
    template<typename T>\
    vec<2, T> operator op (T n, const vec<2, T>& v)\
    {\
        return vec<2, T>(n op v.x, n op v.y);\
    }

template<typename T>
class vec<2, T>
{
public:
    GLM_CLASS_TYPEDEF(T);

    typedef vec<2, T> this_type;

    enum { ELEMENTS = 2 };

    union{
        value_type m[ELEMENTS];
        struct{
            union { value_type x, u, s, w, width; };
            union { value_type y, v, t, h, height; };
        };
    };

public:
    vec() : x(), y(){ /*void*/ }

    template<typename X>
    vec(X scalar) : x(scalar), y(scalar) { /*void*/ }

    template<typename X>
    vec(X vx, X vy) : x(vx), y(vy) { /*void*/ }

    template<typename X>
    vec(const vec<2, X>& v) : x(v.x), y(v.y) { /*void*/ }

    template<typename X>
    vec(const vec<3, X>& v) : x(v.x), y(v.y) { /*void*/ }

    template<typename X>
    vec(const vec<4, X>& v) : x(v.x), y(v.y) { /*void*/ }

    length_t length()const { return ELEMENTS; }

    reference operator[](size_t i) { return m[i]; }
    const_reference operator[](size_t i)const { return m[i]; }

    pointer data() { return m; }
    const_pointer data()const { return m; }

    // operator
    GLM_VEC2_OPERATION(+);
    GLM_VEC2_OPERATION(-);
    GLM_VEC2_OPERATION(*);
    GLM_VEC2_OPERATION(/);

    this_type operator+()const { return *this; }
    this_type operator-()const { return this_type(-x, -y); }
};

GLM_VEC2_OPERATOR_COMMON(+);
GLM_VEC2_OPERATOR_COMMON(-);
GLM_VEC2_OPERATOR_COMMON(*);
GLM_VEC2_OPERATOR_COMMON(/);

#undef GLM_VEC2_OPERATION
#undef GLM_VEC2_OPERATOR_COMMON

}// end namespace glm

#endif// GLM_VEC2_HPP_20211019154130
