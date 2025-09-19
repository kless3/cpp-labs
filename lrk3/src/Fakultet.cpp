#include "../include/Fakultet.h"
#include <iostream>

Fakultet::Fakultet() : facultyName("Unknown") {
    std::cout << "Fakultet constructor: " << facultyName << std::endl;
}

Fakultet::Fakultet(std::string_view name) : facultyName(name) {
    std::cout << "Fakultet parameterized constructor: " << facultyName << std::endl;
}

Fakultet::Fakultet(const Fakultet& other) : facultyName(other.facultyName) {
    std::cout << "Fakultet copy constructor: " << facultyName << std::endl;
}

Fakultet::~Fakultet() {
    std::cout << "Fakultet destructor: " << facultyName << std::endl;
    facultyName.clear();
}

Fakultet& Fakultet::operator=(const Fakultet& other) {
    if (this != &other) {
        facultyName = other.facultyName;
    }
    return *this;
}

void Fakultet::setFacultyName(std::string_view name) {
    facultyName = name;
}

std::string Fakultet::getFacultyName() const {
    return facultyName;
}

void Fakultet::display() const {
    std::cout << "Faculty: " << facultyName << std::endl;
}