// ============================================================================
//
//       Filename:  Print_Vector.hpp
//
//    Description:  Print Vector
//                  Print a vector with elements separated by 'separator'
//                  (default: space)
//
//        Version:  1.0
//        Created:  06/Nov/2014 20:24:34
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <iostream>
#include <vector>
using namespace std;


template<typename T>
void Print_Vector(vector<T> v, const char separator = ' ')
{
    typename vector< T >::iterator it = v.begin();
    cout << *it;

    for (++it; it != v.end(); ++it)
        cout << separator << *it;

    cout << endl;
}
