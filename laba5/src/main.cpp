#include "../include/Menu.h"

using namespace std;

int main() {
    int choice;

    do {
        displayMainMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                workWithIntQueue();
                break;

            case 2:
                workWithDoubleQueue();
                break;

            case 3:
                workWithStringQueue();
                break;

            case 4:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}