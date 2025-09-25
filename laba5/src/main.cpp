#include "../include/menu.h"
#include <iostream>

const int EXIT_OPTION = 4;

int main() {
    int choice;

    do {
        displayMainMenu();
        std::cin >> choice;
        handleMainMenuChoice(choice);
    } while (choice != EXIT_OPTION);

    return 0;
}