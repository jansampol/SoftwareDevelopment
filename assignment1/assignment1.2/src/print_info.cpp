//==============================================================
// Filename : print_info.cpp
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Prints the table of BMI classification
//==============================================================

#include <iostream>

void printInfo() {
    std::cout << "BMI VALUES:" << std::endl;
    std::cout << "Underweight:\tless than 18.5" << std::endl;
    std::cout << "Normal:\t\tbetween 18.5 and 24.9" << std::endl;
    std::cout << "Overweight:\tbetween 25 and 29.9" << std::endl;
    std::cout << "Obese:\t\t30 or greater" << std::endl;
}
