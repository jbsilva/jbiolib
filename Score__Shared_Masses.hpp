// ============================================================================
//
//       Filename:  Score__Shared_Masses.hpp
//
//    Description:  Returns the number of masses shared between the cyclic
//                  spectrum of 'peptide' and 'spectrum'
//
//        Version:  1.0
//        Created:  04/Dez/2014 00:15:12
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include "Cyclic_Spectrum.hpp"
#include "Count_Intersection.hpp"


int Score__Shared_Masses(std::vector<int> peptide, std::vector<int> spectrum)
{
    return Count_Intersection(Cyclic_Spectrum(peptide), spectrum);
}
