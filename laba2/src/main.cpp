#include "../include/String.h"
#include "../include/Menu.h"
#include <iostream>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    String currentString;
    int choice = 0;

    do {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

        handleMenuChoice(choice, currentString);

        if (choice != 7) {
            std::cout << "\nНажмите Enter для продолжения...\n";
            std::cin.get();
        }

    } while (choice != 7);

    return 0;
}