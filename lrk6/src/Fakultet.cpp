#include "../include/Fakultet.h"
#include <iostream>

Fakultet::Fakultet() : facultyName("��������") {
    std::cout << "���������: " << facultyName << std::endl;
}

Fakultet::Fakultet(std::string_view name) : facultyName(name) {
    std::cout << "��������: " << facultyName << std::endl;
}

Fakultet::Fakultet(const Fakultet &other) : facultyName(other.facultyName) {
    std::cout << "������ ����������� �����������: " << facultyName << std::endl;
}

Fakultet::~Fakultet() {
    std::cout << "������ ����������: " << facultyName << std::endl;
    facultyName.clear();
}

Fakultet &Fakultet::operator=(const Fakultet &other) {
    if (this != &other) {
        facultyName = other.facultyName;
    }
    return *this;
}

[[maybe_unused]] void Fakultet::setFacultyName(std::string_view name) {
    facultyName = name;
}

[[maybe_unused]] std::string Fakultet::getFacultyName() const {
    return facultyName;
}

void Fakultet::display() const {
    std::cout << "���������: " << facultyName << std::endl;
}