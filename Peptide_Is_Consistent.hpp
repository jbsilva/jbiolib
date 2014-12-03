// ============================================================================
//
//       Filename:  Peptide_Is_Consistent.hpp
//
//    Description:  Check if 'peptide' is consistent with 'spectrum'.
//                  Spectrum should be sorted.
//
//        Version:  1.0
//        Created:  03/Dez/2014 00:05:03
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <vector>
#include <algorithm>
#include "Linear_Spectrum.hpp"


bool Peptide_Is_Consistent(std::string peptide, std::vector<int> spectrum)
{
    std::vector<int> s_pep = Linear_Spectrum(peptide);
    return std::includes(spectrum.begin(), spectrum.end(), s_pep.begin(), s_pep.end());
}


bool Peptide_Is_Consistent(std::vector<int> peptide, std::vector<int> spectrum)
{
    std::vector<int> s_pep = Linear_Spectrum(peptide);
    return std::includes(spectrum.begin(), spectrum.end(), s_pep.begin(), s_pep.end());
}
