// ============================================================================
//
//       Filename:  D_Neighborhood.hpp
//
//    Description:  D Neighborhood
//
//                  Returns a set containing all DNA strings with the same
//                  length of 'pattern' with at most 'dist' mismatches with
//                  'pattern'.
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


// TODO: Remove redundance to improve performance
void Modify_Position(std::string pattern, int dist, unsigned int idx, std::set<std::string> &neighbors)
{
    if (dist)
    {
        for (unsigned int i = 0; i < 4; ++i)
        {
            pattern[idx] = "ACGT"[i];
            neighbors.insert(pattern);

            for (unsigned int j = idx + 1; j < pattern.length(); ++j)
                Modify_Position(pattern, dist - 1, j, neighbors);
        }
    }
}


std::set<std::string> D_Neighborhood(std::string pattern, int dist)
{
    std::set<std::string> neighbors;

    for (unsigned int i = 0; i < pattern.length(); ++i)
        Modify_Position(pattern, dist, i, neighbors);

    return neighbors;
}
