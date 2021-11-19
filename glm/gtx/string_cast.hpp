/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 string_cast.hpp

 2021-11-15 23:31:37

*/
#ifndef STRING_CAST_HPP_20211115233137
#define STRING_CAST_HPP_20211115233137

#include <sstream>
#include "io.hpp"

namespace cgl{
namespace glm{

template<typename T>
std::string to_string(const T& value)
{
    std::stringstream stm;
    stm << value;
    return stm.str();
}

}// end namespace glm
}// end namespace cgl

#endif// STRING_CAST_HPP_20211115233137