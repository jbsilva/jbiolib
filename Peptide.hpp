// ============================================================================
//
//       Filename:  Peptide.hpp
//
//    Description:
//
//        Version:  1.0
//        Created:  15/Dez/2014 17:11:13
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include "Score__Shared_Masses.hpp"
#include "Peptide_Mass.hpp"
#include "Peptide.hpp"


const auto &Score = Score__Shared_Masses; // Alias for scoring function


class Peptide
{
public:
    std::vector<int> masses;
    int mass;
    int score;

    Peptide(std::vector<int> p, const std::vector<int> spectrum)
    {
        masses = p;
        mass = Peptide_Mass(masses);
        score = Score(masses, spectrum);
    }

    Peptide()
    {
        mass = -1;
        score = -1;
    }
};
