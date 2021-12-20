/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 string_cast.hpp

 2021-11-15 23:31:37

*/
#ifndef GLM_STRING_CAST_HPP_20211115233137
#define GLM_STRING_CAST_HPP_20211115233137

#include <sstream>
#include "io.hpp"



namespace glm{

template<typename T>
std::string to_string(const T& value)
{
    std::stringstream stm;
    stm << value;
    return stm.str();
}

}// end namespace glm

#endif// GLM_STRING_CAST_HPP_20211115233137
