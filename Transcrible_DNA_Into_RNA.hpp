// ============================================================================
//
//       Filename:  Transcrible_DNA_Into_RNA.hpp
//
//    Description:  Transcrible DNA into RNA like the RNA Polymerase
//
//        Version:  1.0
//        Created:  17/Nov/2014 19:15:07
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <string>


std::string Transcrible_DNA_Into_RNA(std::string dna)
{
    for (std::string::iterator it = dna.begin(); it != dna.end(); ++it)
        if (*it == 'T')
            *it = 'U';

    return dna;
}
