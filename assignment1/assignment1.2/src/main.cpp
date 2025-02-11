//==============================================================
// Filename : main.cpp
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Calls the compute_BMI(), the evaluateAndPrintBMI(BMI) and the 
//               function and displays the computed values
//==============================================================

#include <iostream>
#include "../include/compute_BMI.h"

int main() {
    float weight = 70.0;  // Example weight in kg
    float height = 1.75;  // Example height in meters
    float BMI = compute_BMI(weight, height);

    std::cout << "\nBMI for weight " << weight << " and height " << height << " is " << BMI << "\n" << std::endl;
    evaluateAndPrintBMI(BMI);
    printInfo();

    return 0;
}