//==============================================================
// Filename : person.cpp
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description :  Implementation of the Person class. Set name, birth date, and 
//                calculate age, maximum heart rate, and target heart rate ranges.
//==============================================================

#include "../include/person.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <utility>

// Constructor: assign the initial values of all attributes, checking if the dates are correct
Person::Person(const std::string& fName, const std::string& lName, int day, int month, int year)
    : firstName(fName), lastName(lName) {
    if (isValidDate(day, month)) {
        birthDay = day;
        birthMonth = month;
        birthYear = year;
    } else {
        std::cerr << "Invalid date. Please select a correct birth date" << std::endl;
        birthDay = -1;
        birthMonth = -1;
        birthYear = -1;
    }
}

// Get current year using system time
int Person::getCurrentYear() const {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&currentTime);

    return localTime->tm_year + 1900;
}

// Calculate age
int Person::getAge() const {
    if (birthDay == -1 || birthMonth == -1 || birthYear == -1) {
        std::cerr << "Invalid birth date. Age cannot be computed." << std::endl;
        return -1;
    }

    int currentYear = getCurrentYear();

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&currentTime);

    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;

    int age = currentYear - birthYear;

    // Adjust if the birthday has not occurred this year
    if (birthMonth > currentMonth || 
        (birthMonth == currentMonth && birthDay > currentDay)) {
        age--;
    }

    return age;
}

int Person::calculateMaximumHeartRate() const {
    int age = getAge();
    if (age < 0) {
        std::cerr << "Age is invalid. Cannot calculate maximum heart rate." << std::endl;
        return -1;
    }
    return 220 - age;
}

std::pair<int, int> Person::calculateTargetHeartRate() const {
    int max_hr = calculateMaximumHeartRate();
    if (max_hr < 0) {
        std::cerr << "Age is invalid. Cannot calculate Target Heart Rate." << std::endl;
        return std::make_pair(-1, -1);
    }

    int lowerBound = static_cast<int>(max_hr * 0.5);
    int upperBound = static_cast<int>(max_hr * 0.85);

    return std::make_pair(lowerBound, upperBound);
}

// Getter methods
std::string Person::getFirstName() const {
    return firstName;
}
std::string Person::getLastName() const {
    return lastName;
}
int Person::getBirthDay() const {
    return birthDay;
}
int Person::getBirthMonth() const {
    return birthMonth;
}
int Person::getBirthYear() const {
    return birthYear;
}

// Setter for the date of birth
void Person::setDateOfBirth(int day, int month, int year) {
    if (isValidDate(day, month)) {
        birthDay = day;
        birthMonth = month;
        birthYear = year;
    } else {
        std::cerr << "Invalid date. No changes made." << std::endl;
    }
}

// Setter for the full name
void Person::setFullName(const std::string& fName, const std::string& lName) {
    firstName = fName;
    lastName = lName;
}

// Validation of date
bool Person::isValidDate(int day, int month) {
    return (day >= 1 && day <= 31) && (month >= 1 && month <= 12);
}