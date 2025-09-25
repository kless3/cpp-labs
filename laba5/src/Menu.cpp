#include "../include/Menu.h"
#include "../include/Queue.h"
#include <iostream>
#include <string>

using namespace std;

void displayMainMenu() {
    cout << "\n=== Queue Management System ===" << endl;
    cout << "1. Work with integer queue" << endl;
    cout << "2. Work with double queue" << endl;
    cout << "3. Work with string queue" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

template <typename T>
void workWithQueue() {
    Queue<T> queue;
    int choice;
    T value;
    bool success;

    while (true) {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if empty" << endl;
        cout << "5. Get size" << endl;
        cout << "6. Clear queue" << endl;
        cout << "7. Back to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                success = queue.enqueue(value);
                if (success) {
                    cout << "Value enqueued successfully." << endl;
                }
                break;

            case 2:
                success = queue.dequeue(value);
                if (success) {
                    cout << "Dequeued value: " << value << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;

            case 3:
                success = queue.peek(value);
                if (success) {
                    cout << "Front value: " << value << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;

            case 4:
                cout << "Queue is " << (queue.isEmpty() ? "empty" : "not empty") << endl;
                break;

            case 5:
                cout << "Queue size: " << queue.size() << endl;
                break;

            case 6:
                queue.clear();
                cout << "Queue cleared." << endl;
                break;

            case 7:
                return;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}

void handleMainMenuChoice(int choice) {
    switch (choice) {
        case 1:
            workWithQueue<int>();
            break;

        case 2:
            workWithQueue<double>();
            break;

        case 3:
            workWithQueue<string>();
            break;

        case 4:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
    }
}