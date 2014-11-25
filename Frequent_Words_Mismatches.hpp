// ============================================================================
//
//       Filename:  Frequent_Words_Mismatches.hpp
//
//    Description:  Frequent Words with Mismatches
//
//                  Returns a pair containing the number of times the most
//                  frequent k-mers with up to 'dist' mismatches appear in
//                  'text' and a vector with the k-mers strings.
//
//        Version:  1.0
//        Created:  09/Nov/2014 16:46:23
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


std::pair< int, std::vector<std::string> > Frequent_Words_Mismatches(std::string text, int k, int dist)
{
    std::map<std::string, int> patterns;

    for (unsigned long i = 0; i <= text.length() - k; ++i)
    {
        std::set<std::string> neighbors = D_Neighborhood(text.substr(i, k), dist);

        for (std::set<std::string>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
            patterns[*it]++;
    }

    std::vector<std::string> words;
    int max = 0;

    for (std::map<std::string, int>::iterator it = patterns.begin(); it != patterns.end(); ++it)
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
