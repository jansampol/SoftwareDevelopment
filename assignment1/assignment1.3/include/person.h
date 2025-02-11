//==============================================================
// Filename : person.h
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description :  Manages person data and demonstrates heart rate
//                calculations using the Person class methods.
//==============================================================

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
private: // Create the private attributes
    std::string firstName;
    std::string lastName;
    int birthDay;
    int birthMonth;
    int birthYear;

    // Bool variable that will indicate if the date introduced is correct
    bool isValidDate(int day, int month);

public:
    // Constructor: Initialize the object's attributes
    Person(const std::string& fName, const std::string& lName, int day, int month, int year);

    // Getters: Obtain the values of the private attributes
    std::string getFirstName() const;
    std::string getLastName() const;
    int getBirthDay() const;
    int getBirthMonth() const;
    int getBirthYear() const;

    int getCurrentYear() const;
    int getAge() const;

    // Setter: Set values for the private attributes
    void setDateOfBirth(int day, int month, int year); // Change date of birth
    void setFullName(const std::string& fName, const std::string& lName); // Change name and surname
    int calculateMaximumHeartRate() const; // Compute maximum heart rate
    std::pair<int, int> calculateTargetHeartRate() const;
};

#endif
