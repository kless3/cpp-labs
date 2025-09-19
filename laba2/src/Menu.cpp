#include "../include/Menu.h"
#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu() {
    std::cout << "1. Ввести новую строку" << std::endl;
    std::cout << "2. Проверить пустая ли строка (!)" << std::endl;
    std::cout << "3. Получить подстроку ()(int,int)" << std::endl;
    std::cout << "4. Получить символ по индексу []" << std::endl;
    std::cout << "5. Изменить символ по индексу []" << std::endl;
    std::cout << "6. Показать текущую строку" << std::endl;
    std::cout << "7. Выход" << std::endl;
    std::cout << "Выберите опцию: ";
}

void handleInputString(String &currentString) {
    std::cout << "Введите строку (можно с пробелами): ";
    std::cin >> currentString;
    std::cout << "Строка сохранена: " << currentString << std::endl;
}

void handleCheckEmpty(const String &currentString) {
    std::cout << "Текущая строка: " << currentString << std::endl;
    if (!currentString) {
        std::cout << "Строка ПУСТАЯ" << std::endl;
    } else {
        std::cout << "Строка НЕ пустая" << std::endl;
    }
}

void handleGetSubstring(String &currentString) {
    if (!currentString) {
        std::cout << "Строка пустая, невозможно получить подстроку" << std::endl;
        return;
    }

    int start;
    int count;
    std::cout << "Текущая строка: " << currentString << std::endl;
    std::cout << "Введите начальный индекс: ";
    std::cin >> start;
    std::cout << "Введите количество символов: ";
    std::cin >> count;

    String substring = currentString(start, count);
    std::cout << "Подстрока: " << substring << std::endl;
}

void handleGetChar(const String &currentString) {
    if (!currentString) {
        std::cout << "Строка пустая" << std::endl;
        return;
    }

    int index;
    std::cout << "Текущая строка: " << currentString << std::endl;
    std::cout << "Введите индекс: ";
    std::cin >> index;

    std::cout << "Символ по индексу " << index << ": '" << currentString[index] << "'" << std::endl;
}

void handleChangeChar(String &currentString) {
    if (!currentString) {
        std::cout << "Строка пустая" << std::endl;
        return;
    }

    int index;
    char newChar;
    std::cout << "Текущая строка: " << currentString << std::endl;
    std::cout << "Введите индекс: ";
    std::cin >> index;
    std::cout << "Введите новый символ: ";
    std::cin >> newChar;

    currentString[index] = newChar;
    std::cout << "Строка после изменения: " << currentString << std::endl;
}

void handleShowString(const String &currentString) {
    std::cout << "Текущая строка: " << currentString << std::endl;
}

void handleMenuChoice(int choice, String &currentString) {
    try {
        switch (choice) {
            case 1:
                handleInputString(currentString);
                break;
            case 2:
                handleCheckEmpty(currentString);
                break;
            case 3:
                handleGetSubstring(currentString);
                break;
            case 4:
                handleGetChar(currentString);
                break;
            case 5:
                handleChangeChar(currentString);
                break;
            case 6:
                handleShowString(currentString);
                break;
            case 7:
                std::cout << "Выход из программы..." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
                break;
        }
    } catch (const std::exception &e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        clearInputBuffer();
    }
}