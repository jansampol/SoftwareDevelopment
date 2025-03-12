//==============================================================
// Filename    : TwoDayPackage.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Derived class from Package that represents a two-day 
//               delivery service with a flat fee in addition to the 
//               standard cost per kilogram.
//==============================================================

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {

    // In this class there is no private variables

public:
    // Constructor to initialize a TwoDayPackage object
    TwoDayPackage(string s, string sAddr, string r, string rAddr, double w);

    // Overrides the base class method to compute total shipping cost
    double calculateCost() const override;
};

#endif