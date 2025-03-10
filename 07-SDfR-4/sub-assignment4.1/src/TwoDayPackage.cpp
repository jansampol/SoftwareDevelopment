//==============================================================
// Filename    : TwoDayPackage.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include "../include/TwoDayPackage.h"
using namespace std;

TwoDayPackage::TwoDayPackage(string s, string sAddr, string r, string rAddr, double w)
    : Package(s, sAddr, r, rAddr, w) {}

double TwoDayPackage::calculateCost() const {
    return (getWeight() * COST_PER_KG) + FLAT_FEE;
}