//==============================================================
// Filename : sub_assignment1
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Classify the BMI values
//==============================================================

#include "../include/compute_BMI.h"
#include <iostream>

void evaluateAndPrintBMI(const float BMI) {
    if (BMI < 18.5) {
        std::cout << "You are underweight!" << std::endl;
    } else if (BMI >= 18.5 && BMI < 24.9) {
        std::cout << "You have Normal weight" << std::endl;
    } else if (BMI >= 25 && BMI < 29.9) {
        std::cout << "You are overweight" << std::endl;
    } else {
        std::cout << "You are obese" << std::endl;
    }
}