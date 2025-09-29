#include "../include/Menu.h"
#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu() {
    std::cout << "1. Enter a new string" << std::endl;
    std::cout << "2. Check if string is empty (!)" << std::endl;
    std::cout << "3. Get substring ()(int,int)" << std::endl;
    std::cout << "4. Get character by index []" << std::endl;
    std::cout << "5. Change character by index []" << std::endl;
    std::cout << "6. Show current string" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

void handleInputString(String &currentString) {
    std::cout << "Enter a string (spaces allowed): ";
    std::cin >> currentString;
    std::cout << "String saved: " << currentString << std::endl;
}

void handleCheckEmpty(const String &currentString) {
    std::cout << "Current string: " << currentString << std::endl;
    if (!currentString) {
        std::cout << "String is EMPTY" << std::endl;
    } else {
        std::cout << "String is NOT empty" << std::endl;
    }
}

void handleGetSubstring(const String &currentString) {
    if (!currentString) {
        std::cout << "String is empty, cannot get substring" << std::endl;
        return;
    }

    int start;
    int count;
    std::cout << "Current string: " << currentString << std::endl;
    std::cout << "Enter start index: ";
    std::cin >> start;
    std::cout << "Enter number of characters: ";
    std::cin >> count;

    String substring = currentString(start, count);
    std::cout << "Substring: " << substring << std::endl;
}

void handleGetChar(const String &currentString) {
    if (!currentString) {
        std::cout << "String is empty" << std::endl;
        return;
    }

    int index;
    std::cout << "Current string: " << currentString << std::endl;
    std::cout << "Enter index: ";
    std::cin >> index;

    std::cout << "Character at index " << index << ": '" << currentString[index] << "'" << std::endl;
}

void handleChangeChar(String &currentString) {
    if (!currentString) {
        std::cout << "String is empty" << std::endl;
        return;
    }

    int index;
    char newChar;
    std::cout << "Current string: " << currentString << std::endl;
    std::cout << "Enter index: ";
    std::cin >> index;
    std::cout << "Enter new character: ";
    std::cin >> newChar;

    currentString[index] = newChar;
    std::cout << "String after modification: " << currentString << std::endl;
}

void handleShowString(const String &currentString) {
    std::cout << "Current string: " << currentString << std::endl;
}