#include "../include/Fakultet.h"
#include <iostream>

Fakultet::Fakultet() : facultyName("Unknown") {}

Fakultet::Fakultet(const std::string& name) : facultyName(name) {}

Fakultet::Fakultet(const Fakultet& other) : facultyName(other.facultyName) {}

Fakultet::~Fakultet() {}

Fakultet& Fakultet::operator=(const Fakultet& other) {
    if (this != &other) {
        facultyName = other.facultyName;
    }
    return *this;
}

void Fakultet::setFacultyName(const std::string& name) {
    facultyName = name;
}

std::string Fakultet::getFacultyName() const {
    return facultyName;
}

void Fakultet::display() const {
    std::cout << "Faculty: " << facultyName << std::endl;
}