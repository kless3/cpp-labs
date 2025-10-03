#include <utility>

#include "../include/Person.h"

Person::Person(std::string n) : name(std::move(n)) {}

std::string Person::getName() const { return name; }