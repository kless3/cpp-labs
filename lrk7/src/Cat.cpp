#include "../include/Cat.h"
#include <iostream>
#include <sstream>

Cat::Cat() : name("����������"), breed("����������"), age(0) {}

Cat::Cat(std::string_view name, std::string_view breed, int age)
        : name(name), breed(breed), age(age) {}

Cat::Cat(const Cat& other)
        : name(other.name), breed(other.breed), age(other.age) {
    std::cout << "������ ����������� ����������� Cat: " << name << std::endl;
}

Cat::~Cat() {
    std::cout << "������ ���������� Cat: " << name << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        name = other.name;
        breed = other.breed;
        age = other.age;
    }
    return *this;
}

void Cat::setName(std::string_view name) {
    this->name = name;
}

void Cat::setBreed(std::string_view breed) {
    this->breed = breed;
}

void Cat::setAge(int age) {
    if (age >= 0 && age <= 30) {
        this->age = age;
    }
}

std::string Cat::getName() const {
    return name;
}

std::string Cat::getBreed() const {
    return breed;
}

int Cat::getAge() const {
    return age;
}

void Cat::display() const {
    std::cout << "=== ��� ===" << std::endl;
    std::cout << "���: " << name << std::endl;
    std::cout << "������: " << breed << std::endl;
    std::cout << "�������: " << age << " ���" << std::endl;
}

void Cat::saveToFile(std::ofstream& file) const {
    file << "CAT" << std::endl; // ������������� ����
    file << name << std::endl;
    file << breed << std::endl;
    file << age << std::endl;
}

void Cat::loadFromFile(std::ifstream& file) {
    std::getline(file, name);
    std::getline(file, breed);

    std::string ageStr;
    std::getline(file, ageStr);
    age = std::stoi(ageStr);
}

std::string Cat::getType() const {
    return "CAT";
}