// ============================================================================
//
//       Filename:  Integer_Mass_Table.hpp
//
//    Description:  The Integer Mass Table for the 20 standard amino acids
//
//        Version:  1.0
//        Created:  18/Nov/2014 03:06:49
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <map>


const std::map<char, int> Integer_Mass_Table()
{
    std::map<char, int> m;
    m['G'] = 57;        m['T'] = 101;        m['D'] = 115;        m['H'] = 137;
    m['A'] = 71;        m['C'] = 103;        m['K'] = 128;        m['F'] = 147;
    m['S'] = 87;        m['I'] = 113;        m['Q'] = 128;        m['R'] = 156;
    m['P'] = 97;        m['L'] = 113;        m['E'] = 129;        m['Y'] = 163;
    m['V'] = 99;        m['N'] = 114;        m['M'] = 131;        m['W'] = 186;
    return m;
}
