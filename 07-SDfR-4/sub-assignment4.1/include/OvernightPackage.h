//==============================================================
// Filename    : OvernightPackage.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package {
private:

    // Create private constant variables to avoid unexpected changes
    static constexpr double EXTRA_COST_PER_KG2 = 1.10;

public:

    // Constructor to initialize an OvernightPackage object
    OvernightPackage(string s, string sAddr, string r, string rAddr, double w);

    // Overrides the base class method to compute the shipping cost
    double calculateCost() const override;
};

#endif