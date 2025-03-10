//==============================================================
// Filename    : Package.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Base class for different package types. It provides 
//               common attributes and methods for handling package 
//               information and calculating shipping costs.
//==============================================================

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include "Customer.h"
using namespace std;

class Package {
private:
    const Customer& sender;
    const Customer& receiver;
    double weight;
    bool valid;  // Flag to indicate if the package is valid

public:
    // Constructor
    Package(const Customer& s, const Customer& r, double w);

    // Getter methods
    const Customer& getSender() const;
    const Customer& getReceiver() const;
    double getWeight() const;
    bool isValid() const;  // Checks if package is valid

    // Pure virtual function for cost calculation
    virtual double calculateCost() const = 0;

    // Print package details
    virtual void print() const;

    // Virtual destructor
    virtual ~Package() {}
};

#endif