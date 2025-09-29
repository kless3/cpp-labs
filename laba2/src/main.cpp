#include "../include/String.h"
#include "../include/Menu.h"
#include <iostream>

const int EXIT_OPTION = 7;

int main() {
    String currentString;
    int choice = 0;

    do {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

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
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

    } while (choice != EXIT_OPTION);

    return 0;
}