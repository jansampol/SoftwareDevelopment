#include "../include/person.h"
#include <iostream>

int main() {

    // Crear an object Person with initial data
    Person person("Tommy", "Jerry", 16, 6, 1990);

    // Change the name, surname and the date of birth
    person.setFullName("Elvis", "Teck");
    person.setDateOfBirth(2,3,1956);
    

    // Show the data of the patient
    std::cout << "Patient information: \n" << std::endl;
    std::cout << "First Name: " << person.getFirstName() << std::endl; // Show name
    std::cout << "Last Name: " << person.getLastName() << std::endl; // Show surname
    std::cout << "Date of Birth: " << person.getBirthDay() << "/" 
              << person.getBirthMonth() << "/" << person.getBirthYear() << std::endl; // Show date of birth
    std::cout << "Age: " << person.getAge() << std::endl; // Show age
    std::cout << "Maximum Heart rate: " << person.calculateMaximumHeartRate() << std::endl; // Show MHR
    std::cout << "Target Heart Rate: from "<< person.calculateTargetHeartRate().first << " to " 
              << person.calculateTargetHeartRate().second << std::endl; // Show THR
    std::cout << "" << std::endl;
    return 0;
}