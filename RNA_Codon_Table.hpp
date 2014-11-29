// ============================================================================
//
//       Filename:  RNA_Codon_Table.hpp
//
//    Description:  Codon Table. Stop codons (UAA, UAG, UGA) translated as '\0'
//
//        Version:  1.0
//        Created:  10/Nov/2014 02:52:09
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <map>


const std::map<std::string, char> Codon_Table()
{
    std::map<std::string, char> CT;
    CT["AAA"] = 'K';   CT["AAC"] = 'N';   CT["AAG"] = 'K';   CT["AAU"] = 'N';
    CT["ACA"] = 'T';   CT["ACC"] = 'T';   CT["ACG"] = 'T';   CT["ACU"] = 'T';
    CT["AGA"] = 'R';   CT["AGC"] = 'S';   CT["AGG"] = 'R';   CT["AGU"] = 'S';
    CT["AUA"] = 'I';   CT["AUC"] = 'I';   CT["AUG"] = 'M';   CT["AUU"] = 'I';
    CT["CAA"] = 'Q';   CT["CAC"] = 'H';   CT["CAG"] = 'Q';   CT["CAU"] = 'H';
    CT["CCA"] = 'P';   CT["CCC"] = 'P';   CT["CCG"] = 'P';   CT["CCU"] = 'P';
    CT["CGA"] = 'R';   CT["CGC"] = 'R';   CT["CGG"] = 'R';   CT["CGU"] = 'R';
    CT["CUA"] = 'L';   CT["CUC"] = 'L';   CT["CUG"] = 'L';   CT["CUU"] = 'L';
    CT["GAA"] = 'E';   CT["GAC"] = 'D';   CT["GAG"] = 'E';   CT["GAU"] = 'D';
    CT["GCA"] = 'A';   CT["GCC"] = 'A';   CT["GCG"] = 'A';   CT["GCU"] = 'A';
    CT["GGA"] = 'G';   CT["GGC"] = 'G';   CT["GGG"] = 'G';   CT["GGU"] = 'G';
    CT["GUA"] = 'V';   CT["GUC"] = 'V';   CT["GUG"] = 'V';   CT["GUU"] = 'V';
    CT["UAA"] = '\0';  CT["UAC"] = 'Y';   CT["UAG"] = '\0';  CT["UAU"] = 'Y';
    CT["UCA"] = 'S';   CT["UCC"] = 'S';   CT["UCG"] = 'S';   CT["UCU"] = 'S';
    CT["UGA"] = '\0';  CT["UGC"] = 'C';   CT["UGG"] = 'W';   CT["UGU"] = 'C';
    CT["UUA"] = 'L';   CT["UUC"] = 'F';   CT["UUG"] = 'L';   CT["UUU"] = 'F';
    return CT;
}
