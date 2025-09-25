#include "../include/Menu.h"
#include <iostream>
int main() {
    int choice;

    do {
        displayMainMenu();
        std::cin >> choice;
        handleMainMenuChoice(choice);
    } while (choice != 4);

    return 0;
}