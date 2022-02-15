/*
 Copyright (c) 2005-2020 sdragonx (mail:sdragonx@foxmail.com)

 io.hpp

 2021-11-15 20:12:42

*/
#ifndef GLM_IO_HPP_20211115201242
#define GLM_IO_HPP_20211115201242

#include <iostream>
#include "../matrix.hpp"



namespace glm{

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& out, const vec<N, T>& m)
{
    out << "[ ";
    for(size_t i=0; i < N; ++i){
        out << std::fixed;
        out.width(6);
        out.precision(3);
        out << m[i];
        if(i != N - 1){
            out << ", ";
        }
    }
    out << " ]";

    return out;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const mat<4, 4, T>& m)
{
    out << std::endl;
    for(size_t x = 0; x < m.COLS; ++x){
        if(x == 0)
            out << "[[";
        else
            out << " [";
        for(size_t y = 0; y < m.ROWS; ++y){
            out << std::fixed;
            out.width(8);
            out.precision(3);
            out << m[y][x];

            if(y != m.ROWS - 1) {
                out << ",";
            }
            else {
                if(x != m.COLS - 1) {
                    out << ']' << std::endl;
                }
                else {
                    out << "]]" << std::endl;
                }
            }
        }
    }

    return out;
}

}// end namespace glm

#endif// GLM_IO_HPP_20211115201242
