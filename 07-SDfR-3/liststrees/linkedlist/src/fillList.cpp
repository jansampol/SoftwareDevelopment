//==============================================================
// Filename    : fillList.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : Definition of fillList function
//==============================================================

#include <iostream>
#include "List.h"

void fillList(const std::string& str, List<char>& charList) {
    for (char ch : str) {
        charList.insertAtBack(ch);
    }
}