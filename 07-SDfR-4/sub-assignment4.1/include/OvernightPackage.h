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
    static constexpr double COST_PER_KG = 2.50;
    static constexpr double FLAT_FEE = 5.0;
    static constexpr double EXTRA_COST_PER_KG2 = 1.10;

public:
    OvernightPackage(string s, string sAddr, string r, string rAddr, double w);

    double calculateCost() const override;
};

#endif
