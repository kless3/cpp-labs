#include <iostream>
#include "../include/Menu.h"

using namespace std;

int main() {
    string filename = "test.txt";
    Menu menu(filename);
    int choice;

    cout << "File Indexer using " << filename << " as default file" << endl;

    do {
        menu.printMenu();
        cin >> choice;
        cin.ignore();

    } while (menu.handleChoice(choice));

    cout << "Goodbye!" << endl;
    return 0;
}