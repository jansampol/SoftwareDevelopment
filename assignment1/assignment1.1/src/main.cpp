//==============================================================
// Filename : sub_assignment1
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : 
//==============================================================

#include <iostream>
#include "../include/divide.h"

int main() {
    int a = 7;
    int b = 3;
    int c = divide(a, b);
    std::cout << a << "/" << b << "=" << c << std::endl;
    return 0;
}