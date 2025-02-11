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
    int b = 0;

    // Out-of-bounds array access to trigger a runtime error
    int arr[3] = {1, 2, 3};
    std::cout << "Accessing out-of-bounds element: " << arr[5] << std::endl;

    int c = divide(a, b);
    std::cout << a << "/" << b << "=" << c << std::endl;
    return 0;
}