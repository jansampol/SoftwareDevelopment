//==============================================================
// Filename    : TwoDayPackage.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {
private:
    static constexpr double COST_PER_KG = 2.50;
    static constexpr double FLAT_FEE = 5.0;

public:
    TwoDayPackage(string s, string sAddr, string r, string rAddr, double w);

    double calculateCost() const override;
};

#endif

