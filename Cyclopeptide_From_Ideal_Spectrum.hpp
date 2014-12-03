// ============================================================================
//
//       Filename:  Cyclopeptide_From_Ideal_Spectrum.hpp
//
//    Description:  Receives a ideal experimental spectrum and returns peptides
//                  (in mass notation) that generate the same spectrum.
//
//        Version:  1.0
//        Created:  29/Nov/2014 19:36:19
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <vector>
#include "Cyclic_Spectrum.hpp"
#include "Linear_Spectrum.hpp"
#include "Peptide_Mass.hpp"
#include "Peptide_Is_Consistent.hpp"


// Expand each peptide by one
void Expand_Peptide(std::vector< std::vector<int> > &peptides)
{
    std::vector<int> amino_acidos = {57, 71, 87, 97, 99, 101, 103, 113, 114,
                                     115, 128, 129, 131, 137, 147, 156, 163, 186
                                    };
    std::vector< std::vector<int> > new_pep;

    for (const auto p : peptides)
    {
        for (const auto am : amino_acidos)
        {
            std::vector<int> temp = p;
            temp.push_back(am);
            new_pep.push_back(temp);
        }
    }

    peptides = new_pep;
}


// TODO: Maybe lists are faster than vectors
std::vector< std::vector<int> > Cyclopeptide_From_Ideal_Spectrum(std::vector<int> spectrum)
{
    std::vector< std::vector<int> > peptides = { {57}, {71}, {87}, {97}, {99},
        {101}, {103}, {113}, {114}, {115}, {128}, {129}, {131}, {137}, {147},
        {156}, {163}, {186}
    };
    std::vector < std::vector <int> > ans;

    while (!peptides.empty())
    {
        Expand_Peptide(peptides);

        for (std::vector<std::vector <int> >::reverse_iterator p_it = peptides.rbegin(); p_it != peptides.rend(); ++p_it)
        {
            if (Peptide_Mass(*p_it) == spectrum.back()) // Equal masses
            {
                if (Cyclic_Spectrum(*p_it) == spectrum)
                    ans.push_back(*p_it);

                peptides.erase(--p_it.base()); // base has a +1 offset
            }
            else if (!Peptide_Is_Consistent(*p_it, spectrum))
                peptides.erase(--p_it.base());
        }
    }

    return ans;
}
