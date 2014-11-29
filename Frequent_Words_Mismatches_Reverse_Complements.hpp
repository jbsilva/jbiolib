// ============================================================================
//
//       Filename:  Frequent_Words_Mismatches_Reverse_Complements.hpp
//
//    Description:  Returns a pair containing the number of times the most
//                  frequent k-mers with mismatches and reverse complements
//                  appear in a DNA string and a vector with their strings.
//
//        Version:  1.0
//        Created:  09/Nov/2014 17:27:33
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <utility>
#include <vector>
#include <map>
#include <set>
#include "D_Neighborhood.hpp"
#include "Reverse_Complement.hpp"
using namespace std;


pair< int, vector<string> > Frequent_Words_Mismatches_Reverse_Complements(string text, int k, int dist)
{
    map<string, int> patterns;

    for (unsigned long i = 0; i <= text.length() - k; ++i)
    {
        set<string> neighbors = D_Neighborhood(text.substr(i, k), dist);

        for (set<string>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
        {
            string patt = *it;
            patterns[patt]++;
            patterns[Reverse_Complement(patt)]++;
        }
    }

    vector<string> words;
    int max = 0;

    for (map<string, int>::iterator it = patterns.begin(); it != patterns.end(); ++it)
    {
        if (it->second > max)
        {
            words.clear();
            max = it->second;
        }

        if (it->second == max)
            words.push_back(it->first);
    }

    return make_pair(max, words);
}
