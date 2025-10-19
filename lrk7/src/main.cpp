#include <iostream>
#include <string>
#include "../include/FileIndexer.h"

using namespace std;

void printMenu() {
    cout << "\n=== File Indexer Menu ===" << endl;
    cout << "1. Open file and count words" << endl;
    cout << "2. Get word by index" << endl;
    cout << "3. Show total word count" << endl;
    cout << "4. Write single word to file" << endl;
    cout << "5. Write multiple words to file" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose option: ";
}

int main() {
    FileIndexer* indexer = nullptr;
    string filename = "test.txt";
    int choice;

    cout << "File Indexer using test.txt as default file" << endl;

    indexer = new FileIndexer(filename);

    do {
        printMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                if (indexer->openFile()) {
                    cout << "File opened successfully for reading!" << endl;
                    cout << "Total words in file: " << indexer->getWordCount() << endl;
                } else {
                    cout << "Error: Could not open file '" << filename << "'" << endl;
                    cout << "Creating new file..." << endl;
                    if (indexer->openFileForWrite()) {
                        cout << "New file created successfully!" << endl;
                        indexer->closeFile();
                    } else {
                        cout << "Error: Could not create file" << endl;
                    }
                }
                break;
            }

            case 2: {
                if (!indexer->openFile()) {
                    cout << "Error: Could not open file for reading." << endl;
                    break;
                }

                long wordCount = indexer->getWordCount();
                if (wordCount == 0) {
                    cout << "File is empty or could not read word count." << endl;
                    break;
                }

                long index;
                cout << "Enter word index (0 to " << wordCount - 1 << "): ";
                cin >> index;

                if (index >= 0 && index < wordCount) {
                    string word = (*indexer)[index];
                    cout << "Word at index " << index << ": '" << word << "'" << endl;
                } else {
                    cout << "Error: Invalid index. Must be between 0 and " << wordCount - 1 << endl;
                }
                indexer->closeFile();
                break;
            }

            case 3: {
                if (indexer->openFile()) {
                    cout << "Total words in file: " << indexer->getWordCount() << endl;
                    indexer->closeFile();
                } else {
                    cout << "Error: Could not open file for reading." << endl;
                }
                break;
            }

            case 4: {
                string word;
                cout << "Enter word to write: ";
                getline(cin, word);

                if (indexer->writeWord(word)) {
                    cout << "Word '" << word << "' successfully written to file!" << endl;
                } else {
                    cout << "Error: Could not write word to file." << endl;
                }
                break;
            }

            case 5: {
                string words;
                cout << "Enter words to write: ";
                getline(cin, words);

                if (indexer->writeWords(words)) {
                    cout << "Words successfully written to file!" << endl;
                } else {
                    cout << "Error: Could not write words to file." << endl;
                }
                break;
            }

            case 6: {
                delete indexer;
                cout << "Goodbye!" << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

    } while (choice != 6);

    return 0;
}