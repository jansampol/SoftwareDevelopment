//==============================================================
// Filename : compute_BMI.cpp
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Computes the BMI with a given weight and height
//==============================================================

#include "../include/compute_BMI.h"

float compute_BMI(const float weight, const float height) {
    return weight / (height * height);  
}