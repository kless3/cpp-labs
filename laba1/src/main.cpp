#include "../include/ArrayOperations.h"
#include "../include/Menu.h"
#include <iostream>

int main() {
    auto choice = 0;

    do {
        displayMenu();
        choice = getChoice();
        handleChoice(choice);

    } while (choice != 3);

    return 0;
}