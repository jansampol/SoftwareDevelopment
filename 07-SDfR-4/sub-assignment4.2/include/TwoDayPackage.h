//==============================================================
// Filename    : TwoDayPackage.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Represents a package with a two-day shipping option.
//==============================================================

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {
private:
    static constexpr double COST_PER_KG = 2.50;
    static constexpr double FLAT_FEE = 5.0;

public:
    // Constructor to initialize package details
    TwoDayPackage(const Customer& s, const Customer& r, double w);

    // Calculates the shipping cost
    double calculateCost() const override;
};

#endif
