// ============================================================================
//
//       Filename:  Peptide_Str_To_Mass.hpp
//
//    Description:  Converts the representation of a peptide from a string into
//                  a vector with the integer mass of each amino acid
//
//        Version:  1.0
//        Created:  02/Dez/2014 23:25:47
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include "Integer_Mass_Table.hpp"


std::vector<int> Peptide_Str_To_Mass(std::string peptide)
{
    std::map<char, int> m = Integer_Mass_Table();
    std::vector<int> peptide_masses;

    for (unsigned int i = 0; i < peptide.length(); ++i)
        peptide_masses.push_back(m[peptide.at(i)]);

    return peptide_masses;
}
