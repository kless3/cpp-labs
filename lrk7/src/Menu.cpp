#include "../include/Menu.h"
#include "../include/FileIndexer.h"
#include <iostream>
#include <cstring>

void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Read element by index\n";
    std::cout << "2. Write element by index\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose option: ";
}

void handleRead(FileIndexer& indexer) {
    long index;
    std::cout << "Enter index: ";
    std::cin >> index;

    char* element = (char*)indexer[index];
    if (element != nullptr) {
        std::cout << "Element at index " << index << ": " << element << std::endl;
    }
}

void handleWrite(FileIndexer& indexer) {
    long index;
    char data[256];
    std::cout << "Enter index: ";
    std::cin >> index;
    std::cout << "Enter data (max 19 chars): ";
    std::cin.ignore();
    std::cin.getline(data, 256);

    char buffer[20] = {0};
    strncpy(buffer, data, 19);
    indexer.writeElement(index, buffer);
    std::cout << "Data written successfully" << std::endl;
}