#include "../include/Rose.h"
#include <iostream>
#include <sstream>

Rose::Rose() : color("Неизвестно"), variety("Неизвестно"), bloomLevel(0), hasThorns(true) {}

Rose::Rose(std::string_view color, std::string_view variety, int bloomLevel, bool hasThorns)
        : color(color), variety(variety), bloomLevel(bloomLevel), hasThorns(hasThorns) {}

Rose::Rose(const Rose& other)
        : color(other.color), variety(other.variety), bloomLevel(other.bloomLevel), hasThorns(other.hasThorns) {
    std::cout << "Вызван конструктор копирования Rose: " << color << " " << variety << std::endl;
}

Rose::~Rose() {
    std::cout << "Вызван деструктор Rose: " << color << " " << variety << std::endl;
}

Rose& Rose::operator=(const Rose& other) {
    if (this != &other) {
        color = other.color;
        variety = other.variety;
        bloomLevel = other.bloomLevel;
        hasThorns = other.hasThorns;
    }
    return *this;
}

void Rose::setColor(std::string_view color) {
    this->color = color;
}

void Rose::setVariety(std::string_view variety) {
    this->variety = variety;
}

void Rose::setBloomLevel(int bloomLevel) {
    if (bloomLevel >= 0 && bloomLevel <= 10) {
        this->bloomLevel = bloomLevel;
    }
}

void Rose::setHasThorns(bool hasThorns) {
    this->hasThorns = hasThorns;
}

std::string Rose::getColor() const {
    return color;
}

std::string Rose::getVariety() const {
    return variety;
}

int Rose::getBloomLevel() const {
    return bloomLevel;
}

bool Rose::getHasThorns() const {
    return hasThorns;
}

void Rose::display() const {
    std::cout << "=== Роза ===" << std::endl;
    std::cout << "Цвет: " << color << std::endl;
    std::cout << "Сорт: " << variety << std::endl;
    std::cout << "Уровень цветения: " << bloomLevel << "/10" << std::endl;
    std::cout << "Наличие шипов: " << (hasThorns ? "Да" : "Нет") << std::endl;
}

void Rose::saveToFile(std::ofstream& file) const {
    file << "ROSE" << std::endl; // Идентификатор типа
    file << color << std::endl;
    file << variety << std::endl;
    file << bloomLevel << std::endl;
    file << (hasThorns ? "1" : "0") << std::endl;
}

void Rose::loadFromFile(std::ifstream& file) {
    std::getline(file, color);
    std::getline(file, variety);

    std::string bloomStr;
    std::getline(file, bloomStr);
    bloomLevel = std::stoi(bloomStr);

    std::string thornsStr;
    std::getline(file, thornsStr);
    hasThorns = (thornsStr == "1");
}

std::string Rose::getType() const {
    return "ROSE";
}