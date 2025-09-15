#include "../include/Fakultet.h"
#include <iostream>

Fakultet::Fakultet() : facultyName("Unknown") {}

Fakultet::Fakultet(std::string_view name) : facultyName(name) {}

Fakultet::Fakultet(const Fakultet& other) = default;

Fakultet& Fakultet::operator=(const Fakultet& other) = default;

void Fakultet::setFacultyName(std::string_view name) {
    facultyName = name;
}

std::string Fakultet::getFacultyName() const {
    return facultyName;
}

void Fakultet::display() const {
    std::cout << "Faculty: " << facultyName << std::endl;
}