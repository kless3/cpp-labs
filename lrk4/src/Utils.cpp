#include "../include/Utils.h"

void showAllReactions(const std::vector<std::unique_ptr<Person>>& people) {
    for(size_t i = 0; i < people.size(); ++i) {
        for(size_t j = 0; j < people.size(); ++j) {
            if(i != j) {
                people[i]->reactToNewPerson(people[j].get());
            }
        }
    }
}

void addGirl(std::vector<std::unique_ptr<Person>>& people) {
    std::string name;
    std::cout << "Enter girl name: ";
    std::cin >> name;
    people.push_back(std::make_unique<Girl>(name));
}

void addYoungMan(std::vector<std::unique_ptr<Person>>& people) {
    std::string name;
    std::cout << "Enter young man name: ";
    std::cin >> name;
    people.push_back(std::make_unique<YoungMan>(name));
}

void handleMenuChoice(int choice, std::vector<std::unique_ptr<Person>>& people) {
    switch(choice) {
        case 1:
            showAllReactions(people);
            break;
        case 2:
            addGirl(people);
            break;
        case 3:
            addYoungMan(people);
            break;
        case 4:
            std::cout << "Exit..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}
