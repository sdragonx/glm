/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 io.hpp

 2021-11-15 20:12:42

*/
#ifndef GLM_IO_HPP_20211115201242
#define GLM_IO_HPP_20211115201242

#include <iostream>

#include "../vec.hpp"
#include "../mat.hpp"



namespace glm{

template<size_t N, typename T>
std::ostream& operator <<(std::ostream& os, const vec<N, T>& m)
{
    os << "{ ";
    for(size_t i=0; i < N; ++i){
        os << std::fixed;
        os.width(6);
        os.precision(3);
        os << m[i];
        if(i != N - 1){
            os << ", ";
        }
    }
    os << " }";

    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const mat<4, 4, T>& m)
{
    os << "{" << std::endl;
    for(size_t x = 0; x < m.COLS; ++x){
        //os << "\t";
        for(size_t y = 0; y < m.ROWS; ++y){
            os << std::fixed;
            os.width(8);
            os.precision(3);
            os << m[y][x];
            if(y * m.COLS + x < m.length() - 1){
                os << ", ";
            }
        }
        os << std::endl;
    }
    os << "}";

    return os;
}

}// end namespace glm

#endif// GLM_IO_HPP_20211115201242
