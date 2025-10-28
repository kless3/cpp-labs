#include "../include/Menu.h"
#include "../include/Cat.h"
#include "../include/Car.h"
#include "../include/Rose.h"
#include <iostream>
#include <limits>
#include <span>

void displayMenu() {
    std::cout << "\n=== Меню управления объектами ===" << std::endl;
    std::cout << "1. Добавить объект" << std::endl;
    std::cout << "2. Показать все объекты" << std::endl;
    std::cout << "3. Сохранить объекты в файл" << std::endl;
    std::cout << "4. Загрузить объекты из файла" << std::endl;
    std::cout << "5. Доступ к объектам из файла через operator[]" << std::endl;
    std::cout << "6. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addObject(std::span<Object *> &objectsSpan, int &objectCount) {
    std::cout << "Выберите тип объекта:" << std::endl;
    std::cout << "1. Кот" << std::endl;
    std::cout << "2. Автомобиль" << std::endl;
    std::cout << "3. Роза" << std::endl;
    std::cout << "Ваш выбор: ";

    int typeChoice;
    std::cin >> typeChoice;
    clearInputBuffer();

    Object *newObject = nullptr;

    switch (typeChoice) {
        case 1: {
            std::string breed;
            std::string name;
            int age;

            std::cout << "Введите имя кота: ";
            std::getline(std::cin, name);
            std::cout << "Введите породу кота: ";
            std::getline(std::cin, breed);
            std::cout << "Введите возраст кота: ";
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

            std::cout << "Введите марку автомобиля: ";
            std::getline(std::cin, brand);
            std::cout << "Введите модель автомобиля: ";
            std::getline(std::cin, model);
            std::cout << "Введите год выпуска: ";
            std::cin >> year;
            std::cout << "Введите цену: ";
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

            std::cout << "Введите цвет розы: ";
            std::getline(std::cin, color);
            std::cout << "Введите сорт розы: ";
            std::getline(std::cin, variety);
            std::cout << "Введите уровень цветения (0-10): ";
            std::cin >> bloomLevel;
            std::cout << "Есть ли шипы? (1 - да, 0 - нет): ";
            std::cin >> hasThorns;
            clearInputBuffer();

            newObject = new Rose(color, variety, bloomLevel, hasThorns);
            break;
        }
        default:
            std::cout << "Неверный выбор типа объекта!" << std::endl;
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

        std::cout << "Объект успешно добавлен!" << std::endl;
    }
}

void displayObjects(std::span<Object *> objectsSpan) {
    if (objectsSpan.empty()) {
        std::cout << "Нет объектов для отображения." << std::endl;
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
        std::cout << "Ошибка: не удалось открыть файл для записи!" << std::endl;
        return;
    }

    file << objects.size() << std::endl;

    for (const auto &object: objects) {
        object->saveToFile(file);
    }

    file.close();
    std::cout << "Объекты успешно сохранены в файл: " << filename << std::endl;
}

void loadObjectsFromFile(const std::string &filename, std::span<Object *> &objectsSpan, int &objectCount) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл для чтения!" << std::endl;
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
            std::cout << "Неизвестный тип объекта: " << type << std::endl;
            newObjects[i] = nullptr;
            continue;
        }

        newObjects[i]->loadFromFile(file);
    }

    objectsSpan = std::span<Object *>(newObjects, count);
    objectCount = count;

    file.close();
    std::cout << "Объекты успешно загружены из файла: " << filename << std::endl;
}

void demonstrateFileIndexing(const std::string &filename) {
    ObjectFile objectFile(filename);

    int objectCount = objectFile.getObjectCount();
    if (objectCount == 0) {
        std::cout << "Файл пуст. Сначала добавьте объекты и сохраните их." << std::endl;
        return;
    }

    std::cout << "=== Демонстрация доступа к объектам из файла через operator[] ===" << std::endl;
    std::cout << "Всего объектов в файле: " << objectCount << std::endl;

    for (int i = 0; i < objectCount; i++) {
        try {
            std::cout << "\n--- Объект #" << i << " из файла ---" << std::endl;
            Object *object = objectFile[i];
            object->display();
            delete object;
        } catch (const std::invalid_argument &e) {
            std::cout << "Ошибка при доступе к объекту #" << i << ": " << e.what() << std::endl;
        }
    }

    std::cout << "\nДоступ к конкретному объекту по индексу" << std::endl;
    std::cout << "Введите индекс объекта (0-" << objectCount - 1 << "): ";

    int index;
    std::cin >> index;
    clearInputBuffer();

    Object *specificObject = objectFile[index];
    std::cout << "\n--- Найденный объект ---" << std::endl;
    specificObject->display();
    delete specificObject;
}