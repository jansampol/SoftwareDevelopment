//==============================================================
// Filename    : TwoDayPackage.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the TwoDayPackage class
//==============================================================

#include "TwoDayPackage.h"
using namespace std;

TwoDayPackage::TwoDayPackage(const Customer& s, const Customer& r, double w)
    : Package(s, r, w) {}

double TwoDayPackage::calculateCost() const {
    static constexpr double COST_PER_KG = 2.50;
    static constexpr double FLAT_FEE = 5.0;
    return (getWeight() * COST_PER_KG) + FLAT_FEE;
}
