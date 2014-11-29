// ============================================================================
//
//       Filename:  Prefix_Mass.hpp
//
//    Description:  Creates a integer vector with the prefix masses, where
//                  prefix_mass[i] is equal to the sum of the masses of the
//                  first i amino acids in the 'peptide' string.
//
//        Version:  1.0
//        Created:  10/Nov/2014 00:57:36
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
#include "Integer_Mass_Table.hpp"


std::vector<int> Prefix_Mass(std::string peptide)
{
    std::map<char, int> m = Integer_Mass_Table();
    std::vector<int> prefix_mass;
    prefix_mass.resize(peptide.length() + 1);
    prefix_mass[0] = 0;

    for (unsigned int i = 0; i < peptide.length(); ++i)
        prefix_mass[i + 1] = prefix_mass[i] + m[peptide.at(i)];

    return prefix_mass;
}
