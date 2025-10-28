#include "../include/Menu.h"
#include "../include/Cat.h"
#include "../include/Car.h"
#include "../include/Rose.h"
#include <iostream>
#include <limits>
#include <span>

void displayMenu() {
    std::cout << "\n=== ���� ���������� ��������� ===" << std::endl;
    std::cout << "1. �������� ������" << std::endl;
    std::cout << "2. �������� ��� �������" << std::endl;
    std::cout << "3. ��������� ������� � ����" << std::endl;
    std::cout << "4. ��������� ������� �� �����" << std::endl;
    std::cout << "5. ������ � �������� �� ����� ����� operator[]" << std::endl;
    std::cout << "6. �����" << std::endl;
    std::cout << "�������� ��������: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addObject(std::span<Object *> &objectsSpan, int &objectCount) {
    std::cout << "�������� ��� �������:" << std::endl;
    std::cout << "1. ���" << std::endl;
    std::cout << "2. ����������" << std::endl;
    std::cout << "3. ����" << std::endl;
    std::cout << "��� �����: ";

    int typeChoice;
    std::cin >> typeChoice;
    clearInputBuffer();

    Object *newObject = nullptr;

    switch (typeChoice) {
        case 1: {
            std::string breed;
            std::string name;
            int age;

            std::cout << "������� ��� ����: ";
            std::getline(std::cin, name);
            std::cout << "������� ������ ����: ";
            std::getline(std::cin, breed);
            std::cout << "������� ������� ����: ";
            std::cin >> age;
            clearInputBuffer();

            newObject = new Cat(name, breed, age);
            break;
        }
        case 2: {
            std::string model;
            std::string brand;
            int year;
            double price;

            std::cout << "������� ����� ����������: ";
            std::getline(std::cin, brand);
            std::cout << "������� ������ ����������: ";
            std::getline(std::cin, model);
            std::cout << "������� ��� �������: ";
            std::cin >> year;
            std::cout << "������� ����: ";
            std::cin >> price;
            clearInputBuffer();

            newObject = new Car(brand, model, year, price);
            break;
        }
        case 3: {
            std::string color;
            std::string variety;
            int bloomLevel;
            bool hasThorns;

            std::cout << "������� ���� ����: ";
            std::getline(std::cin, color);
            std::cout << "������� ���� ����: ";
            std::getline(std::cin, variety);
            std::cout << "������� ������� �������� (0-10): ";
            std::cin >> bloomLevel;
            std::cout << "���� �� ����? (1 - ��, 0 - ���): ";
            std::cin >> hasThorns;
            clearInputBuffer();

            newObject = new Rose(color, variety, bloomLevel, hasThorns);
            break;
        }
        default:
            std::cout << "�������� ����� ���� �������!" << std::endl;
            return;
    }

    if (newObject) {
        Object **oldObjects = objectsSpan.data();
        auto **newObjects = new Object *[objectCount + 1];

        for (int i = 0; i < objectCount; ++i) {
            newObjects[i] = oldObjects[i];
        }

        newObjects[objectCount] = newObject;
        delete[] oldObjects;

        objectsSpan = std::span<Object *>(newObjects, objectCount + 1);
        objectCount++;

        std::cout << "������ ������� ��������!" << std::endl;
    }
}

void displayObjects(std::span<Object *> objectsSpan) {
    if (objectsSpan.empty()) {
        std::cout << "��� �������� ��� �����������." << std::endl;
    } else {
        for (const auto &object: objectsSpan) {
            object->display();
            std::cout << "-------------------" << std::endl;
        }
    }
}

void saveObjectsToFile(const std::string &filename, std::span<Object *> objects) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "������: �� ������� ������� ���� ��� ������!" << std::endl;
        return;
    }

    file << objects.size() << std::endl;

    for (const auto &object: objects) {
        object->saveToFile(file);
    }

    file.close();
    std::cout << "������� ������� ��������� � ����: " << filename << std::endl;
}

void loadObjectsFromFile(const std::string &filename, std::span<Object *> &objectsSpan, int &objectCount) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "������: �� ������� ������� ���� ��� ������!" << std::endl;
        return;
    }

    for (int i = 0; i < objectCount; ++i) {
        delete objectsSpan[i];
    }
    delete[] objectsSpan.data();

    std::string countStr;
    std::getline(file, countStr);
    int count = std::stoi(countStr);

    auto **newObjects = new Object *[count];

    for (int i = 0; i < count; ++i) {
        std::string type;
        std::getline(file, type);

        if (type == "CAT") {
            newObjects[i] = new Cat();
        } else if (type == "CAR") {
            newObjects[i] = new Car();
        } else if (type == "ROSE") {
            newObjects[i] = new Rose();
        } else {
            std::cout << "����������� ��� �������: " << type << std::endl;
            newObjects[i] = nullptr;
            continue;
        }

        newObjects[i]->loadFromFile(file);
    }

    objectsSpan = std::span<Object *>(newObjects, count);
    objectCount = count;

    file.close();
    std::cout << "������� ������� ��������� �� �����: " << filename << std::endl;
}

void demonstrateFileIndexing(const std::string &filename) {
    ObjectFile objectFile(filename);

    int objectCount = objectFile.getObjectCount();
    if (objectCount == 0) {
        std::cout << "���� ����. ������� �������� ������� � ��������� ��." << std::endl;
        return;
    }

    std::cout << "=== ������������ ������� � �������� �� ����� ����� operator[] ===" << std::endl;
    std::cout << "����� �������� � �����: " << objectCount << std::endl;

    for (int i = 0; i < objectCount; i++) {
        try {
            std::cout << "\n--- ������ #" << i << " �� ����� ---" << std::endl;
            Object *object = objectFile[i];
            object->display();
            delete object;
        } catch (const std::invalid_argument &e) {
            std::cout << "������ ��� ������� � ������� #" << i << ": " << e.what() << std::endl;
        }
    }

    std::cout << "\n������ � ����������� ������� �� �������" << std::endl;
    std::cout << "������� ������ ������� (0-" << objectCount - 1 << "): ";

    int index;
    std::cin >> index;
    clearInputBuffer();

    Object *specificObject = objectFile[index];
    std::cout << "\n--- ��������� ������ ---" << std::endl;
    specificObject->display();
    delete specificObject;
}