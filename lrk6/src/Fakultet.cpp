#include "../include/Fakultet.h"
#include <iostream>

Fakultet::Fakultet() : facultyName("Загружен") {
    std::cout << "Факультет: " << facultyName << std::endl;
}

Fakultet::Fakultet(std::string_view name) : facultyName(name) {
    std::cout << "Факуьтет: " << facultyName << std::endl;
}

Fakultet::Fakultet(const Fakultet &other) : facultyName(other.facultyName) {
    std::cout << "Вызван конструктор копирования: " << facultyName << std::endl;
}

Fakultet::~Fakultet() {
    std::cout << "Вызван деструктор: " << facultyName << std::endl;
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
    std::cout << "Факультет: " << facultyName << std::endl;
}