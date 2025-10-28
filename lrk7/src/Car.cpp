#include "../include/Car.h"
#include <iostream>
#include <sstream>

Car::Car() : brand("Неизвестно"), model("Неизвестно"), year(0), price(0.0) {}

Car::Car(std::string_view brand, std::string_view model, int year, double price)
        : brand(brand), model(model), year(year), price(price) {}

Car::Car(const Car& other)
        : brand(other.brand), model(other.model), year(other.year), price(other.price) {
    std::cout << "Вызван конструктор копирования Car: " << brand << " " << model << std::endl;
}

Car::~Car() {
    std::cout << "Вызван деструктор Car: " << brand << " " << model << std::endl;
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

void Car::setBrand(std::string_view brand) {
    this->brand = brand;
}

void Car::setModel(std::string_view model) {
    this->model = model;
}

void Car::setYear(int year) {
    if (year >= 1900 && year <= 2030) {
        this->year = year;
    }
}

void Car::setPrice(double price) {
    if (price >= 0) {
        this->price = price;
    }
}

std::string Car::getBrand() const {
    return brand;
}

std::string Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

double Car::getPrice() const {
    return price;
}

void Car::display() const {
    std::cout << "=== Автомобиль ===" << std::endl;
    std::cout << "Марка: " << brand << std::endl;
    std::cout << "Модель: " << model << std::endl;
    std::cout << "Год: " << year << std::endl;
    std::cout << "Цена: " << price << " руб." << std::endl;
}

void Car::saveToFile(std::ofstream& file) const {
    file << "CAR" << std::endl; // Идентификатор типа
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