#include "../include/Car.h"
#include <iostream>
#include <sstream>

Car::Car() : brand("����������"), model("����������"), year(0), price(0.0) {}

Car::Car(std::string_view brand, std::string_view model, int year, double price)
        : brand(brand), model(model), year(year), price(price) {}

Car::Car(const Car& other)
        : brand(other.brand), model(other.model), year(other.year), price(other.price) {
    std::cout << "������ ����������� ����������� Car: " << brand << " " << model << std::endl;
}

Car::~Car() {
    std::cout << "������ ���������� Car: " << brand << " " << model << std::endl;
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        brand = other.brand;
        model = other.model;
        year = other.year;
        price = other.price;
    }
    return *this;
}

void Car::display() const {
    std::cout << "=== ���������� ===" << std::endl;
    std::cout << "�����: " << brand << std::endl;
    std::cout << "������: " << model << std::endl;
    std::cout << "���: " << year << std::endl;
    std::cout << "����: " << price << " ���." << std::endl;
}

void Car::saveToFile(std::ofstream& file) const {
    file << "CAR" << std::endl;
    file << brand << std::endl;
    file << model << std::endl;
    file << year << std::endl;
    file << price << std::endl;
}

void Car::loadFromFile(std::ifstream& file) {
    std::getline(file, brand);
    std::getline(file, model);

    std::string yearStr;
    std::getline(file, yearStr);
    year = std::stoi(yearStr);

    std::string priceStr;
    std::getline(file, priceStr);
    price = std::stod(priceStr);
}

std::string Car::getType() const {
    return "CAR";
}