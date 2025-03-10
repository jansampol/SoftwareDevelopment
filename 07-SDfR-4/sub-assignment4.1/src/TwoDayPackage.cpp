//==============================================================
// Filename    : TwoDayPackage.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the TwoDayPackage class, which applies 
//               a flat fee in addition to the standard cost per kilogram.
//==============================================================

#include "../include/TwoDayPackage.h"

using namespace std;

// Constructor initializes a two-day package with sender and receiver details
TwoDayPackage::TwoDayPackage(string s, string sAddr, string r, string rAddr, double w)
    : Package(s, sAddr, r, rAddr, w) {}

// Calculates the total shipping cost
double TwoDayPackage::calculateCost() const {
    return (getWeight() * COST_PER_KG) + FLAT_FEE;
}