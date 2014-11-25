// ============================================================================
//
//       Filename:  Reverse_Complement.hpp
//
//    Description:  Reverse Complement
//                  Returns the string which is the reverse complement of 'dna'
//
//        Version:  1.0
//        Created:  06/Nov/2014 19:29:40
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <string>
#include <algorithm>
#include <map>
using namespace std;


string Reverse_Complement(string dna)
{
    map<char, char> comp;
    comp['A'] = 'T'; comp['C'] = 'G'; comp['G'] = 'C'; comp['T'] = 'A';

    for (string::iterator it = dna.begin(); it != dna.end(); ++it)
        *it = comp[*it];

    reverse(dna.begin(), dna.end());
    return dna;
}
