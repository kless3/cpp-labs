#include "../include/Menu.h"

template<typename T>
void showMenu() {
    std::cout << "1. Enqueue" << std::endl;
    std::cout << "2. Dequeue" << std::endl;
    std::cout << "3. Display Queue" << std::endl;
    std::cout << "4. Linear Search" << std::endl;
    std::cout << "5. Selection Sort" << std::endl;
    std::cout << "6. Clear Queue" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Choose option: ";
}

template<typename T>
void handleEnqueue(Queue<T> &queue) {
    T value;
    std::cout << "Enter value to enqueue: ";
    std::cin >> value;
    queue.enqueue(value);
    std::cout << "Value " << value << " added to queue" << std::endl;
}

template<typename T>
void handleDequeue(Queue<T> &queue) {
    T value = queue.dequeue();
    if (!queue.isEmpty() || value != T()) {
        std::cout << "Dequeued value: " << value << std::endl;
    } else {
        std::cout << "Queue is empty" << std::endl;
    }
}

template<typename T>
void handleDisplay(const Queue<T> &queue) {
    queue.display();
}

template<typename T>
void handleLinearSearch(const Queue<T> &queue) {
    try {
        T value;
        std::cout << "Enter value to search: ";
        std::cin >> value;
        int result = Algorithm<T>::linearSearch(queue, value);
        std::cout << "Value found at position: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Search failed: " << e.what() << std::endl;
    }
}

template<typename T>
void handleSelectionSort(Queue<T> &queue) {
    Algorithm<T>::selectionSort(queue);
    std::cout << "Queue sorted successfully" << std::endl;
    queue.display();
}

template<typename T>
void handleClear(Queue<T> &queue) {
    queue.clear();
    std::cout << "Queue cleared" << std::endl;
}

template<typename T>
void runMenu() {
    Queue<T> queue;
    int choice;

    do {
        showMenu<T>();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleEnqueue<T>(queue);
                break;
            case 2:
                handleDequeue<T>(queue);
                break;
            case 3:
                handleDisplay<T>(queue);
                break;
            case 4:
                handleLinearSearch<T>(queue);
                break;
            case 5:
                handleSelectionSort<T>(queue);
                break;
            case 6:
                handleClear<T>(queue);
                break;
            case 7:
                std::cout << "Exiting program" << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != 7);
}

template void runMenu<int>();
template void runMenu<double>();
template void runMenu<char>();
template void runMenu<std::string>();