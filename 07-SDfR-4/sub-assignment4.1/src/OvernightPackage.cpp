//==============================================================
// Filename    : OvernightPackage.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include "../include/OvernightPackage.h"
using namespace std;

OvernightPackage::OvernightPackage(string s, string sAddr, string r, string rAddr, double w)
    : Package(s, sAddr, r, rAddr, w) {}

double OvernightPackage::calculateCost() const {
    return (getWeight() * COST_PER_KG) + FLAT_FEE + (getWeight() * getWeight() * EXTRA_COST_PER_KG2);
}