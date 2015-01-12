// ============================================================================
//
//       Filename:  Count_Intersection.hpp
//
//    Description:  Returns the number of elements of a that are also in b
//
//        Version:  1.0
//        Created:  04/Dez/2014 00:23:25
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once


template<class InputIt1, class InputIt2>
unsigned int Count_Intersection(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2)
{
    unsigned int count = 0;

    while (first1 != last1 && first2 != last2)
    {
        if (*first1 < *first2)
            ++first1;
        else
        {
            if (!(*first2 < *first1)) // ==
                ++count;

            ++first2;
        }
    }

    return count;
}


unsigned int Count_Intersection(const std::vector<int> &a, const std::vector<int> &b)
{
    return Count_Intersection(a.begin(), a.end(), b.begin(), b.end());
}
