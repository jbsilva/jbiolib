// ============================================================================
//
//       Filename:  Peptide_Mass.hpp
//
//    Description:  Returns the integer mass of a peptide given as a vector
//                  with the integer masses of its amino acids
//
//        Version:  1.0
//        Created:  03/Dez/2014 04:51:28
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <vector>
#include <numeric>


int Peptide_Mass(std::vector<int> peptide)
{
    return std::accumulate(peptide.begin(), peptide.end(), 0);
}
