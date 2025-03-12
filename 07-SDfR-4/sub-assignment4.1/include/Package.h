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
using namespace std;

class Package {
private:
    // Sender and receiver information
    string sender, senderAddress;
    string receiver, receiverAddress;

    // Constant Cost information
    static constexpr double COST_PER_KG = 2.50;
    static constexpr double FLAT_FEE = 5.0;
    
    // Package weight in kilograms (must be positive)
    double weight;
    bool valid; // Flag to test if the package is valid

public:
    // Constructor to initialize package details
    Package(string s, string sAddr, string r, string rAddr, double w);
    
    // Getter methods to retrieve private attributes
    string getSender() const;
    string getSenderAddress() const;
    string getReceiver() const;
    string getReceiverAddress() const;
    double getWeight() const;
    bool isValid() const;

    // Getter for the contstants
    static double getCostPerKg();
    static double getFlatFee();

    // Pure virtual function to enforce cost calculation in derived classes
    virtual double calculateCost() const = 0;

    // Displays package details
    void print() const;

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Package() {}
};

#endif