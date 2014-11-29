// ============================================================================
//
//       Filename:  Translate_RNA_into_Peptide.hpp
//
//    Description:  Translates a RNA string into a aminoacid string 'peptide'
//                  Used in the Protein Translation Problem
//
//        Version:  1.0
//        Created:  10/Nov/2014 03:01:56
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <map>
#include <string>
#include "RNA_Codon_Table.hpp"


std::string Translate_RNA(std::string rna)
{
    std::map<std::string, char> CT = Codon_Table();
    std::string peptide;

    for (unsigned int i = 0; i < rna.length() && CT[rna.substr(i, 3)] != '\0'; i += 3)
        peptide.push_back(CT[rna.substr(i, 3)]);

    return peptide;
}
