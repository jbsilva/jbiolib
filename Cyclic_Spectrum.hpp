// ============================================================================
//
//       Filename:  Cyclic_Spectrum.hpp
//
//    Description:  Returns a vector with the theoretical spectrum of a cyclic
//                  peptide
//
//        Version:  1.0
//        Created:  10/Nov/2014 00:53:27
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
#include "Peptide_Str_To_Mass.hpp"


// Receives a peptide as a vector with the integer masses of each amino acid
std::vector<int> Cyclic_Spectrum(std::vector<int> peptide)
{
    std::vector<int> prefix_mass = Prefix_Mass(peptide);
    std::vector<int> c_spectrum;
    c_spectrum.push_back(0);
    int peptide_mass = prefix_mass[peptide.size()];

    for (unsigned int i = 0; i < peptide.size(); ++i)
        for (unsigned int j = i + 1; j <= peptide.size(); ++j)
        {
            c_spectrum.push_back(prefix_mass[j] - prefix_mass[i]);

            if (i > 0 && j < peptide.size())
                c_spectrum.push_back(peptide_mass - (prefix_mass[j] - prefix_mass[i]));
        }

    sort(c_spectrum.begin(), c_spectrum.end());
    return c_spectrum;
}


std::vector<int> Cyclic_Spectrum(std::string peptide)
{
    return Cyclic_Spectrum(Peptide_Str_To_Mass(peptide));
}
