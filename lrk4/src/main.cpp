#include "../include/Utils.h"

int main() {
    std::vector<std::unique_ptr<Person>> people;

    people.push_back(std::make_unique<Girl>("Anna"));
    people.push_back(std::make_unique<Girl>("Maria"));
    people.push_back(std::make_unique<YoungMan>("Ivan"));
    people.push_back(std::make_unique<YoungMan>("Peter"));

    int choice;
    do {
        std::cout << "1. Show all reactions" << std::endl;
        std::cout << "2. Add girl" << std::endl;
        std::cout << "3. Add young man" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Choose action: ";
        std::cin >> choice;

        handleMenuChoice(choice, people);

    } while (choice != 4);

    return 0;
}