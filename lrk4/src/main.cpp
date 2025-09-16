#include <iostream>
#include <vector>
#include <memory>
#include "../include/Person.h"
#include "../include/Girl.h"
#include "../include/YoungMan.h"

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

        switch(choice) {
            case 1: {
                for(size_t i = 0; i < people.size(); ++i) {
                    for(size_t j = 0; j < people.size(); ++j) {
                        if(i != j) {
                            people[i]->reactToNewPerson(people[j].get());
                        }
                    }
                }
                break;
            }
            case 2: {
                std::string name;
                std::cout << "Enter girl name: ";
                std::cin >> name;
                people.push_back(std::make_unique<Girl>(name));
                break;
            }
            case 3: {
                std::string name;
                std::cout << "Enter young man name: ";
                std::cin >> name;
                people.push_back(std::make_unique<YoungMan>(name));
                break;
            }
            case 4:
                std::cout << "Exit..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while(choice != 4);

    return 0;
}