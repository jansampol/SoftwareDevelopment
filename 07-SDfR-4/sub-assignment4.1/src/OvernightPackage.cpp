//==============================================================
// Filename    : OvernightPackage.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the OvernightPackage class, which 
//               adds an extra charge per kilogram squared to the 
//               standard shipping cost.
//==============================================================

#include "OvernightPackage.h"

using namespace std;

// Constructor initializes an overnight package with sender and receiver details
OvernightPackage::OvernightPackage(string s, string sAddr, string r, string rAddr, double w)
    : Package(s, sAddr, r, rAddr, w) {}

// Calculates the total shipping cost
double OvernightPackage::calculateCost() const {
    return (getWeight() * COST_PER_KG) + FLAT_FEE + (getWeight() * getWeight() * EXTRA_COST_PER_KG2);
}
