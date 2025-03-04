//==============================================================
// Filename    : fillList.cpp
// Authors     : 
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include <iostream>
#include "List.h"

void fillList(const std::string& str, List<char>& charList) {
    for (char ch : str) {
        charList.insertAtBack(ch);
    }
}