#include "../include/Menu.h"

const int EXIT_OPTION = 2;

int main() {
    int choice;

    do {
        displayMainMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                workWithArray();
                break;

            case 2:
                std::cout << "Goodbye!" << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != EXIT_OPTION);

    return 0;
}