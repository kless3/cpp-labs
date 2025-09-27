#include "../include/Menu.h"

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

void handleEnqueue(Queue &queue) {
    int value;
    std::cout << "Enter value to enqueue: ";
    std::cin >> value;
    queue.enqueue(value);
    std::cout << "Value " << value << " added to queue" << std::endl;
}

void handleDequeue(Queue &queue) {
    int value = queue.dequeue();
    if (value != -1) {
        std::cout << "Dequeued value: " << value << std::endl;
    } else {
        std::cout << "Queue is empty" << std::endl;
    }
}

void handleDisplay(const Queue &queue) {
    queue.display();
}

void handleLinearSearch(const Queue &queue) {
    int value;
    std::cout << "Enter value to search: ";
    std::cin >> value;
    int result = Algorithm::linearSearch(queue, value);
    if (result != -1) {
        std::cout << "Value found at position: " << result << std::endl;
    } else {
        std::cout << "Value not found in queue" << std::endl;
    }
}

void handleBubbleSort(Queue &queue) {
    Algorithm::bubbleSort(queue);
    std::cout << "Queue sorted successfully" << std::endl;
    queue.display();
}

void handleClear(Queue &queue) {
    queue.clear();
    std::cout << "Queue cleared" << std::endl;
}