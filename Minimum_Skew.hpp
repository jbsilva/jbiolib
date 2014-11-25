// ============================================================================
//
//       Filename:  Minimum_Skew.hpp
//
//    Description:  Minimum Skew
//
//                  Returns a vector with the position of the smallest elements
//                  of Skew_Vector(dna)
//
//        Version:  1.0
//        Created:  08/Nov/2014 16:51:47
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <algorithm>
#include <utility>
#include "Skew_Vector.hpp"


std::vector<int> Minimum_Skew(std::string dna)
{
    std::vector<int>skew = Skew_Vector(dna);
    std::vector< std::pair<int, unsigned int> > skew_idx;

    for (unsigned int i = 0; i < skew.size(); ++i)
        skew_idx.push_back(std::make_pair(skew[i], i));

    sort(skew_idx.begin(), skew_idx.end());
    std::vector<int>min_skew;

    for (int i = 0; skew_idx[i].first == skew_idx[0].first; ++i)
        min_skew.push_back(skew_idx[i].second);

    return min_skew;
}
