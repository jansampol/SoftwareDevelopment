//==============================================================
// Filename    : TwoDayPackage.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the TwoDayPackage class
//==============================================================

#include "../include/TwoDayPackage.h"
using namespace std;

// Class constructor
TwoDayPackage::TwoDayPackage(const Customer& s, const Customer& r, double w)
    : Package(s, r, w) {}

// Define the calculatecost() method for this derived class
double TwoDayPackage::calculateCost() const {

    return (getWeight() * getCostPerKg()) + getFlatFee();
}