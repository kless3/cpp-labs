#include "../include/Queue.h"
#include "../include/Menu.h"
#include <iostream>



int main() {
    Queue queue;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleEnqueue(queue);
                break;
            case 2:
                handleDequeue(queue);
                break;
            case 3:
                handleDisplay(queue);
                break;
            case 4:
                handleLinearSearch(queue);
                break;
            case 5:
                handleBubbleSort(queue);
                break;
            case 6:
                handleClear(queue);
                break;
            case 7:
                std::cout << "Exiting program" << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != 7);

    return 0;
}