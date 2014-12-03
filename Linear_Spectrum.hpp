// ============================================================================
//
//       Filename:  Linear_Spectrum.hpp
//
//    Description:  Receives a peptide (a string or vector with integer masses)
//                  and returns a integer vector corresponding to its the
//                  linear spectrum
//
//        Version:  1.0
//        Created:  09/Nov/2014 21:10:42
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include "Prefix_Mass.hpp"


std::vector<int> Linear_Spectrum(std::vector<int> peptide)
{
    std::vector<int> prefix_mass = Prefix_Mass(peptide);
    std::vector<int> l_spectrum;
    l_spectrum.push_back(0);

    for (unsigned int i = 0; i < peptide.size(); ++i)
        for (unsigned int j = i + 1; j <= peptide.size(); ++j)
            l_spectrum.push_back(prefix_mass[j] - prefix_mass[i]);

    sort(l_spectrum.begin(), l_spectrum.end());
    return l_spectrum;
}


std::vector<int> Linear_Spectrum(std::string peptide)
{
    return Linear_Spectrum(Peptide_Str_To_Mass(peptide));
}
