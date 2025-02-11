//==============================================================
// Filename : main.cpp
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Calls the devide function defined in divide.cpp and performs the operation
//==============================================================

#include <iostream>
#include "../include/divide.h"

int main() {
    int a = 7;
    int b = 10;
    int c = divide(a, b);
    std::cout << a << "/" << b << "=" << c << std::endl;
    return 0;
}