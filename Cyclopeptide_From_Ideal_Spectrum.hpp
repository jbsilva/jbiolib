// ============================================================================
//
//       Filename:  Cyclopeptide_From_Ideal_Spectrum.hpp
//
//    Description:  Receives a ideal experimental spectrum and returns peptides
//                  (in mass notation) that generate the same spectrum.
//
//                  TODO: Maybe lists are faster than vectors
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
#include "Expand_Peptide.hpp"


std::vector< std::vector<int> > Cyclopeptide_From_Ideal_Spectrum(std::vector<int> spectrum)
{
    std::vector< std::vector<int> > peptides;
    std::vector < std::vector <int> > ans;

    do
    {
        Expand_Peptide(peptides);

        // Iterates backwards to keep the iterator valid after erasing elements
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
    while (!peptides.empty());

    return ans;
}
