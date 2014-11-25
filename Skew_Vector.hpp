// ============================================================================
//
//       Filename:  Skew_Vector.hpp
//
//    Description:  Skew Vector
//
//                  Returns the Skew Vector
//
//        Version:  1.0
//        Created:  08/Nov/2014 15:46:54
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <vector>


std::vector<int> Skew_Vector(std::string dna)
{
    std::vector<int> skew;
    skew.resize(dna.length() + 1);
    skew[0] = 0;

    for (unsigned int i = 0, j = 1; i < dna.length(); ++i, ++j)
        if (dna.at(i) == 'C')
            skew[j] = skew[j - 1] - 1;
        else if (dna.at(i) == 'G')
            skew[j] = skew[j - 1] + 1;
        else
            skew[j] = skew[j - 1];

    return skew;
}
