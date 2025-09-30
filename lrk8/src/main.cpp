#include "../include/Deque.h"
#include "../include/Menu.h"
#include <iostream>

int main() {
    Deque deque;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleEnqueueFront(deque);
                break;
            case 2:
                handleEnqueueRear(deque);
                break;
            case 3:
                handleDequeueFront(deque);
                break;
            case 4:
                handleDequeueRear(deque);
                break;
            case 5:
                handleDisplay(deque);
                break;
            case 6:
                handleLinearSearch(deque);
                break;
            case 7:
                handleBubbleSort(deque);
                break;
            case 8:
                handleClear(deque);
                break;
            case 9:
                std::cout << "Exiting program" << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != 9);

    return 0;
}