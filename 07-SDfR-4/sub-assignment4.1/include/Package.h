//==============================================================
// Filename    : Package.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
using namespace std;

class Package {
private:
    string sender, senderAddress;
    string receiver, receiverAddress;
    double weight;

public:
    Package(string s, string sAddr, string r, string rAddr, double w);
    
    // Métodos getter
    string getSender() const;
    string getSenderAddress() const;
    string getReceiver() const;
    string getReceiverAddress() const;
    double getWeight() const;

    virtual double calculateCost() const = 0; // Pure virtual function
    virtual void print() const;

    virtual ~Package() {}
};

#endif
