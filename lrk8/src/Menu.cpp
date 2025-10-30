#include "../include/Menu.h"

template<typename T>
void showMenu() {
    std::cout << "1. Enqueue Front" << std::endl;
    std::cout << "2. Enqueue Rear" << std::endl;
    std::cout << "3. Dequeue Front" << std::endl;
    std::cout << "4. Dequeue Rear" << std::endl;
    std::cout << "5. Display Deque" << std::endl;
    std::cout << "6. Linear Search" << std::endl;
    std::cout << "7. Selection Sort" << std::endl;
    std::cout << "8. Clear Deque" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Choose option: ";
}

template<typename T>
void handleEnqueueFront(Deque<T> &deque) {
    T value;
    std::cout << "Enter value to enqueue at front: ";
    std::cin >> value;
    deque.enqueueFront(value);
    std::cout << "Value " << value << " added to front" << std::endl;
}

template<typename T>
void handleEnqueueRear(Deque<T> &deque) {
    T value;
    std::cout << "Enter value to enqueue at rear: ";
    std::cin >> value;
    deque.enqueueRear(value);
    std::cout << "Value " << value << " added to rear" << std::endl;
}

template<typename T>
void handleDequeueFront(Deque<T> &deque) {
    T value = deque.dequeueFront();
    if (!deque.isEmpty() || value != T()) {
        std::cout << "Dequeued value from front: " << value << std::endl;
    } else {
        std::cout << "Deque is empty" << std::endl;
    }
}

template<typename T>
void handleDequeueRear(Deque<T> &deque) {
    T value = deque.dequeueRear();
    if (!deque.isEmpty() || value != T()) {
        std::cout << "Dequeued value from rear: " << value << std::endl;
    } else {
        std::cout << "Deque is empty" << std::endl;
    }
}

template<typename T>
void handleDisplay(const Deque<T> &deque) {
    deque.display();
}

template<typename T>
void handleLinearSearch(const Deque<T> &deque) {
    T value;
    std::cout << "Enter value to search: ";
    std::cin >> value;
    int result = Algorithm<T>::linearSearch(deque, value);
    if (result != -1) {
        std::cout << "Value found at position: " << result << std::endl;
    } else {
        std::cout << "Value not found in deque" << std::endl;
    }
}

template<typename T>
void handleSelectionSort(Deque<T> &deque) {
    Algorithm<T>::selectionSort(deque);
    std::cout << "Deque sorted successfully" << std::endl;
    deque.display();
}

template<typename T>
void handleClear(Deque<T> &deque) {
    deque.clear();
    std::cout << "Deque cleared" << std::endl;
}

template<typename T>
void runMenu() {
    Deque<T> deque;
    int choice;

    do {
        showMenu<T>();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleEnqueueFront<T>(deque);
                break;
            case 2:
                handleEnqueueRear<T>(deque);
                break;
            case 3:
                handleDequeueFront<T>(deque);
                break;
            case 4:
                handleDequeueRear<T>(deque);
                break;
            case 5:
                handleDisplay<T>(deque);
                break;
            case 6:
                handleLinearSearch<T>(deque);
                break;
            case 7:
                handleSelectionSort<T>(deque);
                break;
            case 8:
                handleClear<T>(deque);
                break;
            case 9:
                std::cout << "Exiting program" << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != 9);
}

template void runMenu<int>();
template void runMenu<double>();
template void runMenu<char>();
template void runMenu<std::string>();