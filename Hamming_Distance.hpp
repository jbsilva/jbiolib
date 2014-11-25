// ============================================================================
//
//       Filename:  Hamming_Distance.hpp
//
//    Description:  Hamming Distance
//
//                  Returns the Hamming Distance between two strings.
//
//        Version:  1.0
//        Created:  06/Nov/2014 19:36:47
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <string>


int Hamming_Distance(std::string a, std::string b)
{
    if (a.length() != b.length())
        return -1;

    int dist = 0;

    for (std::string::iterator it_a = a.begin(), it_b = b.begin(); it_a != a.end(); ++it_a, ++it_b)
        if (*it_a != *it_b)
            dist++;

    return dist;
}
