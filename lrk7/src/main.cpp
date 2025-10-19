#include <iostream>
#include <string>
#include "../include/FileIndexer.h"

using namespace std;

void printMenu() {
    cout << "\n=== File Indexer Menu ===" << endl;
    cout << "1. Open file and count words" << endl;
    cout << "2. Get word by index" << endl;
    cout << "3. Show total word count" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose option: ";
}

int main() {
    FileIndexer* indexer = nullptr;
    string filename = "test.txt"; // Используем test.txt как имя файла по умолчанию
    int choice;

    cout << "File Indexer using test.txt as default file" << endl;

    do {
        printMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                if (indexer) {
                    delete indexer;
                    indexer = nullptr;
                }

                cout << "Using file: " << filename << endl;
                indexer = new FileIndexer(filename);
                if (indexer->openFile()) {
                    cout << "File opened successfully!" << endl;
                    cout << "Total words in file: " << indexer->getWordCount() << endl;
                } else {
                    cout << "Error: Could not open file '" << filename << "'" << endl;
                    cout << "Please make sure test.txt exists in the current directory." << endl;
                    delete indexer;
                    indexer = nullptr;
                }
                break;
            }

            case 2: {
                if (!indexer) {
                    cout << "Error: No file opened. Please open a file first (option 1)." << endl;
                    break;
                }

                long index;
                cout << "Enter word index (0 to " << indexer->getWordCount() - 1 << "): ";
                cin >> index;

                if (index >= 0 && index < indexer->getWordCount()) {
                    string word = (*indexer)[index];
                    cout << "Word at index " << index << ": '" << word << "'" << endl;
                } else {
                    cout << "Error: Invalid index. Must be between 0 and " << indexer->getWordCount() - 1 << endl;
                }
                break;
            }

            case 3: {
                if (!indexer) {
                    cout << "Error: No file opened. Please open a file first (option 1)." << endl;
                } else {
                    cout << "Total words in file: " << indexer->getWordCount() << endl;
                }
                break;
            }

            case 4: {
                if (indexer) {
                    delete indexer;
                }
                cout << "Goodbye!" << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

    } while (choice != 4);

    return 0;
}