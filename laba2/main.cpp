#include "String.h"
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

int main() {
    setlocale(LC_ALL, "Rus");
    String currentString;
    int choice = 0;

    do {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

        try {
            switch (choice) {
                case 1: {
                    std::cout << "������� ������ (����� � ���������): ";
                    std::cin >> currentString;
                    std::cout << "������ ���������: " << currentString << std::endl;
                    break;
                }

                case 2: {
                    std::cout << "������� ������: " << currentString << std::endl;
                    if (!currentString) {
                        std::cout << "������ ������" << std::endl;
                    } else {
                        std::cout << "������ �� ������" << std::endl;
                    }
                    break;
                }

                case 3: {
                    if (!currentString) {
                        std::cout << "������ ������, ���������� �������� ���������" << std::endl;
                        break;
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
                    break;
                }

                case 4: {
                    if (!currentString) {
                        std::cout << "������ ������" << std::endl;
                        break;
                    }

                    int index;
                    std::cout << "������� ������: " << currentString << std::endl;
                    std::cout << "������� ������: ";
                    std::cin >> index;

                    std::cout << "������ �� ������� " << index << ": '" << currentString[index] << "'" << std::endl;
                    break;
                }

                case 5: {
                    if (!currentString) {
                        std::cout << "������ ������" << std::endl;
                        break;
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
                    break;
                }

                case 6: {
                    std::cout << "������� ������: " << currentString << std::endl;
                    break;
                }

                case 7: {
                    std::cout << "����� �� ���������..." << std::endl;
                    break;
                }

                default: {
                    std::cout << "�������� �����. ���������� �����." << std::endl;
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "������: " << e.what() << std::endl;
            clearInputBuffer();
        }

        if (choice != 7) {
            std::cout << "\n������� Enter ��� �����������...";
            std::cin.get();
        }

    } while (choice != 7);

    return 0;
}