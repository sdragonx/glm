/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 glm.hpp

 2021-11-15 20:14:00

*/
#ifndef GLM_HPP_20211115201400
#define GLM_HPP_20211115201400

#include "detail/setup.hpp"

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "mat2.hpp"
#include "mat3.hpp"
#include "mat4.hpp"

#include "detail/logical.hpp"

#include "geometric.hpp"
#include "trigonometric.hpp"
#include "gtx/io.hpp"
#include "gtx/string_cast.hpp"

namespace cgl{
namespace glm{

typedef vec<2, float> vec2;
typedef vec<3, float> vec3;
typedef vec<4, float> vec4;

typedef vec<2, double> dvec2;
typedef vec<3, double> dvec3;
typedef vec<4, double> dvec4;

typedef vec<2, int8_t> i8vec2;
typedef vec<3, int8_t> i8vec3;
typedef vec<4, int8_t> i8vec4;

typedef vec<2, uint8_t> u8vec2;
typedef vec<3, uint8_t> u8vec3;
typedef vec<4, uint8_t> u8vec4;

typedef vec<2, int16_t> i16vec2;
typedef vec<3, int16_t> i16vec3;
typedef vec<4, int16_t> i16vec4;

typedef vec<2, uint16_t> u16vec2;
typedef vec<3, uint16_t> u16vec3;
typedef vec<4, uint16_t> u16vec4;

typedef vec<2, int32_t> i32vec2;
typedef vec<3, int32_t> i32vec3;
typedef vec<4, int32_t> i32vec4;

typedef vec<2, uint32_t> u32vec2;
typedef vec<3, uint32_t> u32vec3;
typedef vec<4, uint32_t> u32vec4;

typedef vec<2, int32_t> ivec2;
typedef vec<3, int32_t> ivec3;
typedef vec<4, int32_t> ivec4;

typedef vec<2, uint32_t> uvec2;
typedef vec<3, uint32_t> uvec3;
typedef vec<4, uint32_t> uvec4;

typedef mat<2, 2, float> mat2;
typedef mat<2, 2, float> mat2x2;
typedef mat<2, 3, float> mat2x3;
typedef mat<2, 4, float> mat2x4;

typedef mat<3, 3, float> mat3;
typedef mat<3, 2, float> mat3x2;
typedef mat<3, 3, float> mat3x3;
typedef mat<3, 4, float> mat3x4;

typedef mat<4, 4, float> mat4;
typedef mat<4, 2, float> mat4x2;
typedef mat<4, 3, float> mat4x3;
typedef mat<4, 4, float> mat4x4;

}// end namespace glm
}// end namespace cgl

using namespace cgl;

#endif// GLM_HPP_20211115201400
