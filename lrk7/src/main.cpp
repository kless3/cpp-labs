#include "../include/Menu.h"
#include <iostream>
#include <span>
#include <Windows.h>

const int EXIT_OPTION = 6;
const std::string DATA_FILE = "objects.txt";

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Object** objects = nullptr;
    int objectCount = 0;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

        std::span<Object*> objectsSpan(objects, objectCount);

        switch (choice) {
            case 1:
                addObject(objectsSpan, objectCount);
                objects = objectsSpan.data();
                break;

            case 2:
                displayObjects(objectsSpan);
                break;

            case 3:
                saveObjectsToFile(DATA_FILE, objectsSpan);
                break;

            case 4:
                loadObjectsFromFile(DATA_FILE, objectsSpan, objectCount);
                objects = objectsSpan.data();
                break;

            case 5:
                demonstrateFileIndexing(DATA_FILE);
                break;

            case 6:
                std::cout << "Выход из программы..." << std::endl;
                break;

            default:
                std::cout << "Неправильный выбор. Попробуйте еще раз." << std::endl;
        }
    } while (choice != EXIT_OPTION);

    for (int i = 0; i < objectCount; ++i) {
        delete objects[i];
    }
    delete[] objects;

    return 0;
}