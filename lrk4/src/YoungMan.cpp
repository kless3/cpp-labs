#include "../include/YoungMan.h"
#include <iostream>

YoungMan::YoungMan(const std::string& n) : Person(n) {}

void YoungMan::reactToNewPerson(const Person* other) const {
    std::cout << name << " (young man): ";
    std::cout << "Hello! Nice to meet you" << std::endl;
}