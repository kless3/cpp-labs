#include "../include/String.h"
#include "../include/Menu.h"
#include <iostream>
#include <locale.h>

const int EXIT_OPTION = 7;

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
                    std::cout << "����� �� ���������..." << std::endl;
                    break;
                default:
                    std::cout << "�������� �����. ���������� �����." << std::endl;
                    break;
            }
        } catch (const std::exception &e) {
            std::cout << "������: " << e.what() << std::endl;
            clearInputBuffer();
        }

        if (choice != 7) {
            std::cout << "\n������� Enter ��� �����������...\n";
            std::cin.get();
        }

    } while (choice != EXIT_OPTION);

    return 0;
}