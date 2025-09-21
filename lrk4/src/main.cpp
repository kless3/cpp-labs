#include "../include/Utils.h"
#include <iostream>

int main() {
    int capacity = 10;
    int count = 0;
    Person** people = new Person*[capacity];

    people[count++] = new Girl("Anna");
    people[count++] = new Girl("Maria");
    people[count++] = new YoungMan("Ivan");
    people[count++] = new YoungMan("Peter");

    int choice;
    do {
        std::cout << "1. Show all reactions" << std::endl;
        std::cout << "2. Add girl" << std::endl;
        std::cout << "3. Add young man" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Choose action: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                showAllReactions(people, count);
                break;
            case 2:
                addGirl(&people, &count, &capacity);
                break;
            case 3:
                addYoungMan(&people, &count, &capacity);
                break;
            case 4:
                std::cout << "Exit..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }

    } while (choice != 4);

    for (int i = 0; i < count; ++i) {
        delete people[i];
    }
    delete[] people;

    return 0;
}