#include "../include/Queue.h"
#include <iostream>

void showMenu() {
    std::cout << "\n=== Queue Operations ===" << std::endl;
    std::cout << "1. Enqueue" << std::endl;
    std::cout << "2. Dequeue" << std::endl;
    std::cout << "3. Display Queue" << std::endl;
    std::cout << "4. Linear Search" << std::endl;
    std::cout << "5. Bubble Sort" << std::endl;
    std::cout << "6. Clear Queue" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Choose option: ";
}

int main() {
    Queue queue;
    int choice, value, result;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to enqueue: ";
                std::cin >> value;
                queue.enqueue(value);
                std::cout << "Value " << value << " added to queue" << std::endl;
                break;

            case 2:
                value = queue.dequeue();
                if (value != -1) {
                    std::cout << "Dequeued value: " << value << std::endl;
                } else {
                    std::cout << "Queue is empty" << std::endl;
                }
                break;

            case 3:
                queue.display();
                break;

            case 4:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                result = Algorithm::linearSearch(queue, value);
                if (result != -1) {
                    std::cout << "Value found at position: " << result << std::endl;
                } else {
                    std::cout << "Value not found in queue" << std::endl;
                }
                break;

            case 5:
                Algorithm::bubbleSort(queue);
                std::cout << "Queue sorted successfully" << std::endl;
                queue.display();
                break;

            case 6:
                queue.clear();
                std::cout << "Queue cleared" << std::endl;
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