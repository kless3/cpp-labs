#include <iostream>
#include "../include/Menu.h"
using namespace std;

const string FILENAME = "test.txt";

int main() {
    string filename = FILENAME;
    FileIndexer indexer(filename);
    int choice;

    cout << "File Indexer using " << filename << " as default file" << endl;

    do {
        printMenu();
        cin >> choice;
        cin.ignore();

    } while (handleChoice(indexer, filename, choice));

    cout << "Goodbye!" << endl;
    return 0;
}