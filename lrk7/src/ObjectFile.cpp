#include "../include/ObjectFile.h"
#include "../include/Cat.h"
#include "../include/Car.h"
#include "../include/Rose.h"
#include <fstream>
#include <stdexcept>

ObjectFile::ObjectFile(std::string filename) : filename(std::move(filename)) {}

Object* ObjectFile::operator[](int index) const {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Не удалось открыть файл: " + filename);
    }

    std::string countStr;
    std::getline(file, countStr);
    if (int objectCount = std::stoi(countStr); index < 0 || index >= objectCount) {
        file.close();
        throw std::out_of_range("Индекс объекта вне диапазона");
    }

    for (int i = 0; i < index; i++) {
        std::string type;
        std::getline(file, type);

        if (type == "CAT") {
            for (int j = 0; j < 3; j++) std::getline(file, type);
        } else if (type == "CAR") {
            for (int j = 0; j < 4; j++) std::getline(file, type);
        } else if (type == "ROSE") {
            for (int j = 0; j < 4; j++) std::getline(file, type);
        }
    }

    std::string type;
    std::getline(file, type);

    Object* object = nullptr;

    if (type == "CAT") {
        object = new Cat();
        object->loadFromFile(file);
    } else if (type == "CAR") {
        object = new Car();
        object->loadFromFile(file);
    } else if (type == "ROSE") {
        object = new Rose();
        object->loadFromFile(file);
    } else {
        throw std::invalid_argument("Неизвестный тип объекта: " + type);
    }

    file.close();
    return object;
}

int ObjectFile::getObjectCount() const {
    std::ifstream file(filename);
    if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof()) {
        return 0;
    }

    std::string countStr;
    std::getline(file, countStr);
    file.close();

    return std::stoi(countStr);
}