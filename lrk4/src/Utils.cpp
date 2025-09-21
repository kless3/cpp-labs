#include "../include/Utils.h"
#include <iostream>

void showAllReactions(Person** people, int count) {
    for(int i = 0; i < count; ++i) {
        for(int j = 0; j < count; ++j) {
            if(i != j) {
                people[i]->reactToNewPerson(people[j]);
            }
        }
    }
}

void resizeArray(Person*** people, int* capacity) {
    int newCapacity = *capacity * 2;
    Person** newArray = new Person*[newCapacity];

    for (int i = 0; i < *capacity; ++i) {
        newArray[i] = (*people)[i];
    }

    delete[] *people;
    *people = newArray;
    *capacity = newCapacity;
}

void addGirl(Person*** people, int* count, int* capacity) {
    if (*count >= *capacity) {
        resizeArray(people, capacity);
    }

    std::string name;
    std::cout << "Enter girl name: ";
    std::cin >> name;

    (*people)[(*count)++] = new Girl(name);
}

void addYoungMan(Person*** people, int* count, int* capacity) {
    if (*count >= *capacity) {
        resizeArray(people, capacity);
    }

    std::string name;
    std::cout << "Enter young man name: ";
    std::cin >> name;

    (*people)[(*count)++] = new YoungMan(name);
}