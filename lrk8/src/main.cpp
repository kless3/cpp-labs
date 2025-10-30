#include "../include/Menu.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Choose data type:" << std::endl;
    std::cout << "1. int" << std::endl;
    std::cout << "2. double" << std::endl;
    std::cout << "3. char" << std::endl;
    std::cout << "4. string" << std::endl;
    std::cout << "Enter choice: ";

    int typeChoice;
    std::cin >> typeChoice;

    switch (typeChoice) {
        case 1:
            runMenu<int>();
            break;
        case 2:
            runMenu<double>();
            break;
        case 3:
            runMenu<char>();
            break;
        case 4:
            runMenu<std::string>();
            break;
        default:
            std::cout << "Invalid type choice" << std::endl;
            break;
    }

    return 0;
}