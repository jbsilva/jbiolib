// ============================================================================
//
//       Filename:  D_Neighborhood.hpp
//
//    Description:  D Neighborhood
//
//                  Returns a set containing all DNA strings with the same
//                  length of 'str' with at most 'dist' mismatches with 'str'.
//
//        Version:  1.0
//        Created:  09/Nov/2014 00:36:29
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <string>
#include <set>


void Permute(std::string str, unsigned int idx, int dist, std::set<std::string> &neighbors)
{
    if (idx == str.length())
        neighbors.insert(str);
    else
    {
        if (dist > 0)
        {
            char temp = str[idx];

            for (int i = 0; i < 4; ++i)
            {
                str[idx] = "ACTG"[i];

                if (str[idx] == temp)
                    Permute(str, idx + 1, dist, neighbors);
                else
                    Permute(str, idx + 1, dist - 1, neighbors);
            }

            str[idx] = temp;
        }
        else
            Permute(str, idx + 1, dist, neighbors);
    }
}


std::set<std::string> D_Neighborhood(std::string str, int dist)
{
    std::set<std::string> neighbors;
    Permute(str, 0, dist, neighbors);
    return neighbors;
}
