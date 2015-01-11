// ============================================================================
//
//       Filename:  Expand_Peptide.hpp
//
//    Description:  Receives a vector of peptides (each as a vector of integer
//                  masses) and adds one amino acid to each of those peptides
//
//        Version:  1.0
//        Created:  04/Dez/2014 02:49:43
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once


void Expand_Peptide(std::vector< std::vector<int> > &peptides)
{
    std::vector<int> amino_acidos = {57, 71, 87, 97, 99, 101, 103, 113, 114,
                                     115, 128, 129, 131, 137, 147, 156, 163, 186
                                    };
    std::vector< std::vector<int> > new_pep;

    if (peptides.empty())
    {
        peptides = { {57}, {71}, {87}, {97}, {99}, {101}, {103}, {113}, {114},
            {115}, {128}, {129}, {131}, {137}, {147}, {156}, {163}, {186}
        };
    }
    else
    {
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
}
