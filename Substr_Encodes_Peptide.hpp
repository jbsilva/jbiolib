// ============================================================================
//
//       Filename:  Substr_Encodes_Peptide.hpp
//
//    Description:  Returns all substrings of 'text' that encode a given amino
//                  acid sequence (peptide)
//                  TODO: optimization
//
//        Version:  1.0
//        Created:  17/Nov/2014 18:50:50
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <vector>
#include <string>
#include "Transcrible_DNA_Into_RNA.hpp"
#include "Reverse_Complement.hpp"
#include "Translate_RNA_into_Peptide.hpp"


vector<std::string> Substr_Encodes_Peptide(std::string text, std::string peptide)
{
    vector<std::string> substrs;

    for (unsigned int i = 0; i <= text.length() - 3 * peptide.length(); ++i)
    {
        std::string sub = text.substr(i, 3 * peptide.length());

        if (Translate_RNA(Transcrible_DNA_Into_RNA(sub)) == peptide ||
                Translate_RNA(Transcrible_DNA_Into_RNA(Reverse_Complement(sub))) == peptide)
            substrs.push_back(sub);
    }

    return substrs;
}
