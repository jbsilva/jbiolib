// ============================================================================
//
//       Filename:  Leaderboard_Cyclopeptide_Sequencing.hpp
//
//    Description:  Receives an experimental spectrum and an integer n and
//                  returns the peptide with the highest score
//
//        Version:  1.0
//        Created:  04/Dez/2014 02:44:45
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
#include "Peptide_Is_Consistent.hpp"
#include "Expand_Peptide.hpp"
#include "Peptide.hpp"


// Function to order the peptides by score
bool comp_peptide_score(Peptide a, Peptide b)
{
    return a.score > b.score;
}


// Keeps only the n (plus ties with the nth) peptides with hightest scores
void Cut(std::vector<Peptide> &peptides, const unsigned int n)
{
    // There is nothing to cut
    if (peptides.size() <= n)
        return;

    // Order peptides by score
    sort(peptides.begin(), peptides.end(), comp_peptide_score);
    // Find the last peptide that will be kept
    std::vector<Peptide>::iterator it = peptides.begin() + n - 1;
    int nth_score = it->score;

    while (it != peptides.end() && it->score == nth_score)
        ++it;

    // Erase all the other peptides with lower scores
    peptides.erase(it, peptides.end());
}


Peptide Leaderboard_Cyclopeptide_Sequencing(const std::vector<int> spectrum, unsigned int n)
{
    std::vector<Peptide> peptides;
    Peptide leader_peptide;

    do
    {
        Expand_Peptide(peptides, spectrum);

        // Iterates backwards to keep the iterator valid after erasing elements
        for (std::vector<Peptide>::reverse_iterator p_it = peptides.rbegin(); p_it != peptides.rend(); ++p_it)
        {
            if (p_it->mass == spectrum.back()) // Equal masses
            {
                if (p_it->score > leader_peptide.score)
                    leader_peptide = *p_it;

                peptides.erase(--p_it.base()); // base has a +1 offset
            }
            else if (p_it->mass > spectrum.back())
                peptides.erase(--p_it.base()); // base has a +1 offset
        }

        Cut(peptides, n);
    }
    while (!peptides.empty());

    return leader_peptide;
}
