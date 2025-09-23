#include "../include/Girl.h"
#include <iostream>

Girl::Girl(const std::string& n) : Person(n) {}

void Girl::reactToNewPerson(const Person* other) const {
    std::cout << name << " (girl): ";
    std::cout << "Hello! My name is " << name << std::endl;
}