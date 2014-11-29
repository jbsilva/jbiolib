// ============================================================================
//
//       Filename:  Peptides_With_Mass.hpp
//
//    Description:  Count the number of possible peptides with a given mass 'm'
//                  I also left a solution using recursion commented.
//
//        Version:  1.0
//        Created:  18/Nov/2014 04:40:21
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <vector>


/* With recursion
unsigned long long count(std::vector<unsigned long long> &t, int AM[], int m)
{
    if (m < 0) return 0;    // Can't get negative mass
    if (m == 0) return 1;   // There is only 1 way to get mass 0: no amino acids
    if (t[m]) return t[m];  // Alredy calculated this before?
    for (int i = 0; i < 18; ++i) t[m] += count(t, AM, m - AM[i]);
    return t[m];
}*/


unsigned long long int Peptides_With_Mass(int m)
{
    // Amino acids integer masses
    int AM[18] = {57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186};
    std::vector<unsigned long long int> t(m + 1);
    t[0] = 1;

    for (int i = 0; i <= m; ++i)
        for (int j = 0; j < 18; ++j)
            if (i - AM[j] >= 0)
                t[i] += t[i - AM[j]];

    return t[m];
}
