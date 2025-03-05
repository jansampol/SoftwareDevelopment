//==============================================================
// Filename    : isValidInteger.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : Define the isValidInteger function
//==============================================================

#include <iostream>
#include <sstream>
#include <string>
#include "isValidInteger.h"

bool isValidInteger(const std::string &str) {
    std::istringstream iss(str);
    int value;
    char extra;
    return (iss >> value) && !(iss >> extra); // Ensure it is a single integer value
}