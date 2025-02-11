//==============================================================
// Filename : main.cpp
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Calls the divide function defined in divide.cpp and performs the operation
//==============================================================

#include <iostream>
#include "divide.h"

int main() {
    int a = 7;
    int b = 3;
    int c = divide(a, b);
    std::cout << a << "/" << b << "=" << c << std::endl;
    return 0;
}