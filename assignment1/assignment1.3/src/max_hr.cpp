#include "../include/person.h"
#include <iostream>

int calculateMaximumHeartRate(const int age) {
    if (age < 0) {
        std::cerr << "Invalid age. Please enter a non-negative value." << std::endl;
        return -1;  // Return -1 for invalid input
    }
    return 220 - age;
}