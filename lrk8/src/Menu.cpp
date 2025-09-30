#include "../include/Menu.h"

void showMenu() {
    std::cout << "1. Enqueue Front" << std::endl;
    std::cout << "2. Enqueue Rear" << std::endl;
    std::cout << "3. Dequeue Front" << std::endl;
    std::cout << "4. Dequeue Rear" << std::endl;
    std::cout << "5. Display Deque" << std::endl;
    std::cout << "6. Linear Search" << std::endl;
    std::cout << "7. Bubble Sort" << std::endl;
    std::cout << "8. Clear Deque" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Choose option: ";
}

void handleEnqueueFront(Deque &deque) {
    int value;
    std::cout << "Enter value to enqueue at front: ";
    std::cin >> value;
    deque.enqueueFront(value);
    std::cout << "Value " << value << " added to front" << std::endl;
}

void handleEnqueueRear(Deque &deque) {
    int value;
    std::cout << "Enter value to enqueue at rear: ";
    std::cin >> value;
    deque.enqueueRear(value);
    std::cout << "Value " << value << " added to rear" << std::endl;
}

void handleDequeueFront(Deque &deque) {
    int value = deque.dequeueFront();
    if (value != -1) {
        std::cout << "Dequeued value from front: " << value << std::endl;
    } else {
        std::cout << "Deque is empty" << std::endl;
    }
}

void handleDequeueRear(Deque &deque) {
    int value = deque.dequeueRear();
    if (value != -1) {
        std::cout << "Dequeued value from rear: " << value << std::endl;
    } else {
        std::cout << "Deque is empty" << std::endl;
    }
}

void handleDisplay(const Deque &deque) {
    deque.display();
}

void handleLinearSearch(const Deque &deque) {
    int value;
    std::cout << "Enter value to search: ";
    std::cin >> value;
    int result = Algorithm::linearSearch(deque, value);
    if (result != -1) {
        std::cout << "Value found at position: " << result << std::endl;
    } else {
        std::cout << "Value not found in deque" << std::endl;
    }
}

void handleBubbleSort(Deque &deque) {
    Algorithm::bubbleSort(deque);
    std::cout << "Deque sorted successfully" << std::endl;
    deque.display();
}

void handleClear(Deque &deque) {
    deque.clear();
    std::cout << "Deque cleared" << std::endl;
}