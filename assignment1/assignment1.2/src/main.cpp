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
    float weight, height;

    // Ask the user for input
    std::cout << "Enter your weight (kg): ";
    std::cin >> weight;

    std::cout << "Enter your height (m): ";
    std::cin >> height;

    // Compute BMI
    float BMI = compute_BMI(weight, height);

    // Display results
    std::cout << "\nBMI for weight " << weight << " kg and height " << height << " m is " << BMI << "\n" << std::endl;
    evaluateAndPrintBMI(BMI);
    printInfo();

    return 0;
}