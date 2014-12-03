// ============================================================================
//
//       Filename:  Print_Matrix.hpp
//
//    Description:  Helper function to print matrices (vector of vectors)
//
//        Version:  1.0
//        Created:  18/Nov/2014 07:44:20
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <iostream>
#include <iomanip>
#include <vector>


template<typename T>
void Print_Matrix(std::vector< std::vector<T> > m, int width = 3)
{
    int lins = m.size();
    int cols = m[0].size();

    for (int i = 0; i < lins; ++i)
    {
        for (int j = 0; j < cols; ++j)
            cout << setw(width) << m[i][j];

        cout << endl;
    }
}
