#include "../include/Menu.h"
#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu() {
    std::cout << "1. ������ ����� ������" << std::endl;
    std::cout << "2. ��������� ������ �� ������ (!)" << std::endl;
    std::cout << "3. �������� ��������� ()(int,int)" << std::endl;
    std::cout << "4. �������� ������ �� ������� []" << std::endl;
    std::cout << "5. �������� ������ �� ������� []" << std::endl;
    std::cout << "6. �������� ������� ������" << std::endl;
    std::cout << "7. �����" << std::endl;
    std::cout << "�������� �����: ";
}

void handleInputString(String &currentString) {
    std::cout << "������� ������ (����� � ���������): ";
    std::cin >> currentString;
    std::cout << "������ ���������: " << currentString << std::endl;
}

void handleCheckEmpty(const String &currentString) {
    std::cout << "������� ������: " << currentString << std::endl;
    if (!currentString) {
        std::cout << "������ ������" << std::endl;
    } else {
        std::cout << "������ �� ������" << std::endl;
    }
}

void handleGetSubstring(const String &currentString) {
    if (!currentString) {
        std::cout << "������ ������, ���������� �������� ���������" << std::endl;
        return;
    }

    int start;
    int count;
    std::cout << "������� ������: " << currentString << std::endl;
    std::cout << "������� ��������� ������: ";
    std::cin >> start;
    std::cout << "������� ���������� ��������: ";
    std::cin >> count;

    String substring = currentString(start, count);
    std::cout << "���������: " << substring << std::endl;
}

void handleGetChar(const String &currentString) {
    if (!currentString) {
        std::cout << "������ ������" << std::endl;
        return;
    }

    int index;
    std::cout << "������� ������: " << currentString << std::endl;
    std::cout << "������� ������: ";
    std::cin >> index;

    std::cout << "������ �� ������� " << index << ": '" << currentString[index] << "'" << std::endl;
}

void handleChangeChar(String &currentString) {
    if (!currentString) {
        std::cout << "������ ������" << std::endl;
        return;
    }

    int index;
    char newChar;
    std::cout << "������� ������: " << currentString << std::endl;
    std::cout << "������� ������: ";
    std::cin >> index;
    std::cout << "������� ����� ������: ";
    std::cin >> newChar;

    currentString[index] = newChar;
    std::cout << "������ ����� ���������: " << currentString << std::endl;
}

void handleShowString(const String &currentString) {
    std::cout << "������� ������: " << currentString << std::endl;
}
