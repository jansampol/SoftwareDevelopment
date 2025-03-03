//==============================================================
// Filename    : isValidInteger.cpp
// Authors     : 
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
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