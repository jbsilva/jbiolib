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


std::vector<int> Cyclic_Spectrum(std::string peptide)
{
    std::vector<int> prefix_mass = Prefix_Mass(peptide);
    std::vector<int> c_spectrum;
    c_spectrum.push_back(0);
    int peptide_mass = prefix_mass[peptide.length()];

    for (unsigned int i = 0; i < peptide.length(); ++i)
        for (unsigned int j = i + 1; j <= peptide.length(); ++j)
        {
            c_spectrum.push_back(prefix_mass[j] - prefix_mass[i]);

            if (i > 0 && j < peptide.length())
                c_spectrum.push_back(peptide_mass - (prefix_mass[j] - prefix_mass[i]));
        }

    sort(c_spectrum.begin(), c_spectrum.end());
    return c_spectrum;
}
