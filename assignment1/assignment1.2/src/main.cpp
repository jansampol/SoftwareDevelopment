#include <iostream>
#include "../include/compute_BMI.h"

int main() {
    float weight = 70.0;  // Example weight in kg
    float height = 1.75;  // Example height in meters
    float BMI = compute_BMI(weight, height);

    std::cout << "BMI for weight " << weight << " and height " << height << " is " << BMI << std::endl;
    evaluateAndPrintBMI(BMI);
    printInfo();

    return 0;
}