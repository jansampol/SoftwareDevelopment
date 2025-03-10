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
    static constexpr double COST_PER_KG = 2.50;
    static constexpr double FLAT_FEE = 5.0;
    static constexpr double EXTRA_COST_PER_KG2 = 1.10;

    return (getWeight() * COST_PER_KG) + FLAT_FEE + (getWeight() * getWeight() * EXTRA_COST_PER_KG2);
}
