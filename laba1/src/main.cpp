#include "../include/Menu.h"

const int EXIT_OPTION = 3;

int main() {
    auto choice = 0;

    do {bhmjjhmjbjk
        displayMenu();
        choice = getChoice();

        switch (choice) {
            case 1:
                processIntersection();
                break;
            case 2:
                processUnion();
                break;
            case 3:
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Try again." << std::endl;
                break;
        }

    } while (choice != EXIT_OPTION);

    return 0;
}