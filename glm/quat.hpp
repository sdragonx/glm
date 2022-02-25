/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 quat.hpp

 2022-02-20 19:41:53

*/
#ifndef GLM_QUAT_HPP_20220220194153
#define GLM_QUAT_HPP_20220220194153

#include "detail/constants.hpp"



namespace glm {


template<typename T>
class qua
{
public:
    GLM_CLASS_TYPEDEF(T);
    typedef qua this_type;

    enum { ELEMENTS = 4 };

    union
    {
        value_type m[ELEMENTS];
        struct
        {
            value_type x, y, z, w;
        };
    };

public:
    qua() : x(), y(), z(), w()
    {
    }

    qua(const qua& q) : x(q.x), y(q.y), z(q.z), w(q.w)
    {
    }

    template<typename X>
    qua(const qua<X>& q) :
        x(static_cast<value_type>(q.x)),
        y(static_cast<value_type>(q.y)),
        z(static_cast<value_type>(q.z)),
        w(static_cast<value_type>(q.w))
    {
    }

    qua(T s, const vec<3, T>& v) : x(v.x), y(v.y), z(v.z), w(s)
    {
    }

    qua(T qw, T qx, T qy, T qz) : x(qx), y(qy), z(qz), w(qw)
    {
    }

    qua(const vec<3, value_type>& eulerAngle)
    {
        vec<3, value_type> c = glm::cos(eulerAngle * value_type(0.5));
        vec<3, value_type> s = glm::sin(eulerAngle * value_type(0.5));

        this->w = c.x * c.y * c.z + s.x * s.y * s.z;
        this->x = s.x * c.y * c.z - c.x * s.y * s.z;
        this->y = c.x * s.y * c.z + s.x * c.y * s.z;
        this->z = c.x * c.y * s.z - s.x * s.y * c.z;
    }

    // 从两个归一化轴创建四元数
    // u    第一个归一化的轴
    // v    第二个归一化的轴
    // 
    // http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
    qua(const vec<3, value_type>& u, const vec<3, value_type>& v);

    qua(const mat<3, 3, value_type>& m);
    qua(const mat<4, 4, value_type>& m);

    explicit operator mat<3, 3, T>() const;

    explicit operator mat<4, 4, T>() const;

    length_t length()const { return ELEMENTS; }

    reference operator[](size_t i) { return m[i]; }
    const_reference operator[](size_t i)const { return m[i]; }

    pointer data() { return m; }
    const_pointer data()const { return m; }

    this_type operator+()const { return *this; }
    this_type operator-()const { return this_type(-w, -x, -y, -z); }
};

typedef qua<float> quat;

}// end namespace glm

#endif// GLM_QUAT_HPP_20220220194153
