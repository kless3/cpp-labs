#include "../include/Person.h"
#include <iostream>

Person::Person(const std::string &n) : name(n) {}

std::string Person::getName() const { return name; }