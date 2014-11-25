// ============================================================================
//
//       Filename:  Pattern_Positions.hpp
//
//    Description:  Pattern Positions
//                  Returns a vector with all the starting positions where
//                  'pattern' appears in 'text'. Considering overlaps.
//
//        Version:  1.0
//        Created:  06/Nov/2014 19:31:25
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
//
// ============================================================================
#pragma once
#include <string>
#include <vector>


const std::vector<int> Pattern_Positions(std::string text, std::string pattern)
{
    std::vector<int> positions;
    std::size_t pos = -1; // The overflow is expected

    while ((pos = text.find(pattern, pos + 1)) != std::string::npos)
        positions.push_back(pos);

    return positions;
}
