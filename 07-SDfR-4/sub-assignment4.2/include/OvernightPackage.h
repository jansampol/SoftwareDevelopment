//==============================================================
// Filename    : OvernightPackage.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Represents a package with an overnight shipping option.
//==============================================================

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package {
private:
    // Private constant variables for the cost
    static constexpr double EXTRA_COST_PER_KG2 = 1.10;

public:
    // Constructor to initialize package details
    OvernightPackage(const Customer& s, const Customer& r, double w);

    // Calculates the shipping cost
    double calculateCost() const override;
};

#endif
