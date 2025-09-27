#include "../include/Menu.h"

const int EXIT_OPTION = 4;

int main() {
    int choice;

    do {
        displayMainMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                inputEmployeesToFile();
                break;

            case 2:
                readEmployeesFromFile();
                break;

            case 3:
                clearEmployeesFile();
                break;

            case 4:
                std::cout << "Goodbye!" << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != EXIT_OPTION);

    return 0;
}