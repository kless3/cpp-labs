#include "../include/Menu.h"

const int EXIT_OPTION = 3;

int main() {
    auto choice = 0;

    do {
        displayMenu();
        choice = getChoice();
        handleChoice(choice);

    } while (choice != EXIT_OPTION);

    return 0;
}