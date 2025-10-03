#include "../include/FileIndexer.h"
#include "../include/Menu.h"
#include <iostream>

int main() {
    FileIndexer indexer(20);

    if (!indexer.openFile()) {
        std::cout << "Error creating file. Exiting." << std::endl;
        return 1;
    }

    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleRead(indexer);
                break;
            case 2:
                handleWrite(indexer);
                break;
            case 3:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

}