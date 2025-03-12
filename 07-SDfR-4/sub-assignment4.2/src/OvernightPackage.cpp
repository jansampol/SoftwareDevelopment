//==============================================================
// Filename    : OvernightPackage.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the OvernightPackage class
//==============================================================

#include "../include/OvernightPackage.h"
using namespace std;

OvernightPackage::OvernightPackage(const Customer& s, const Customer& r, double w)
    : Package(s, r, w) {}

double OvernightPackage::calculateCost() const {

    return (getWeight() * getCostPerKg()) + getFlatFee() + (getWeight() * getWeight() * EXTRA_COST_PER_KG2);
}