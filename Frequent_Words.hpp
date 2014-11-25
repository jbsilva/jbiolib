// ============================================================================
//
//       Filename:  Frequent_Words.hpp
//
//    Description:  Frequent Words
//                  Returns a pair with the number of times the most frequent
//                  k-mers appear in 'text' and a vector with all most frequent
//                  k-mers.
//
//        Version:  1.0
//        Created:  05/Nov/2014 20:09:35
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
using namespace std;


pair< int, vector<string> > Frequent_Words(string text, int k)
{
    map<string, int> patterns;

    for (unsigned long i = 0; i <= text.length() - k; ++i)
        patterns[text.substr(i, k)]++;

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
