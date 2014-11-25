// ============================================================================
//
//       Filename:  Find_Clumps.hpp
//
//    Description:  Find Clumps
//
//                  Returns a vector with all distinct k-mers forming
//                  (L,t)-clumps in 'genome'.
//
//        Version:  1.0
//        Created:  08/Nov/2014 15:44:47
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;


vector<string> Find_Clumps(string genome, unsigned long k, unsigned long L, unsigned long t)
{
    map< string, vector<unsigned long> > patterns;
    map< string, vector<unsigned long> >::iterator it;
    vector<string> k_mers;

    for (unsigned long i = 0; i <= genome.length() - k; ++i)
        patterns[genome.substr(i, k)].push_back(i);

    for (it = patterns.begin(); it != patterns.end(); ++it)
        if (it->second.size() >= t)
        {
            for (unsigned long i = 0, j = i + t - 1; i <= it->second.size() - t; ++i, ++j)

                // The last character of the last match must be in the interval
                if (it->second[j] + k - 1 - it->second[i] < L)
                {
                    k_mers.push_back(it->first);
                    break;
                }
        }

    return k_mers;
}
