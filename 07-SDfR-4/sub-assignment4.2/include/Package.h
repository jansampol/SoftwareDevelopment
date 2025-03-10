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

#include "Customer.h"
#include <iostream>
using namespace std;

class Package {
private:
    // Sender and receiver information
    const Customer& sender;
    const Customer& receiver;

    // Package weight in kilograms (must be positive)
    double weight;

public:
    // Constructor to initialize package details
    Package(const Customer& s, const Customer& r, double w);
    
    // Getter methods to retrieve private attributes
    const Customer& getSender() const;
    const Customer& getReceiver() const;
    double getWeight() const;

    // Pure virtual function to enforce cost calculation in derived classes
    virtual double calculateCost() const = 0;

    // Displays package details
    virtual void print() const;

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Package() {}
};

#endif

