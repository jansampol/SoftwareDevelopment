//==============================================================
// Filename : sub_assignment1
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Defines the BMI function by 
//==============================================================

#include "../include/compute_BMI.h"

float compute_BMI(const float weight, const float height) {
    return weight / (height * height);  
}