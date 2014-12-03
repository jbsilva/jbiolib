// ============================================================================
//
//       Filename:  Print_Auto.hpp
//
//    Description:  Prints elements separated by spaces
//                  This file requires C++11
//
//        Version:  1.0
//        Created:  09/Nov/2014 01:14:05
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <iostream>


template<typename T>
void Print_Auto(T x, string separator = " ", const std::string end = "\n")
{
    bool first = true;

    for (const auto &el : x)
    {
        if (first)
        {
            first = false;
            std::cout << el;
        }
        else
            std::cout << separator << el;
    }

    std::cout << end;
}
