// ============================================================================
//
//       Filename:  Approximate_Pattern_Matching.hpp
//
//    Description:  Approximate Pattern Matching Problem
//
//                  Returns a vector with the starting positions where
//                  'pattern' appears as a substring of 'text' with at most
//                  'mismatches' mismatches.
//
//        Version:  1.0
//        Created:  08/Nov/2014 21:25:11
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#include <string>
#include <vector>
#include "Hamming_Distance.hpp"


std::vector<unsigned int> Aprox_Pattern_Match(std::string text, std::string pattern, int mismatches)
{
    std::vector<unsigned int> substr_idx;

    for (unsigned int i = 0; i <= text.length() - pattern.length(); ++i)
        if (Hamming_Distance(text.substr(i, pattern.length()), pattern) <= mismatches)
            substr_idx.push_back(i);

    return substr_idx;
}
