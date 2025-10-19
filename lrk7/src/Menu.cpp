#include "../include/Menu.h"
#include <iostream>

using namespace std;

void printMenu() {
    cout << "\n=== File Indexer Menu ===" << endl;
    cout << "1. Open file and count words" << endl;
    cout << "2. Get word by index" << endl;
    cout << "3. Show total word count" << endl;
    cout << "4. Write word to file" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose option: ";
}

bool handleOpenFile(FileIndexer& indexer, const std::string& filename) {
    if (indexer.openFile()) {
        cout << "File opened successfully for reading!" << endl;
        cout << "Total words in file: " << indexer.getWordCount() << endl;
        return true;
    } else {
        cout << "Error: Could not open file '" << filename << "'" << endl;
        cout << "Creating new file..." << endl;
        if (indexer.openFileForWrite()) {
            cout << "New file created successfully!" << endl;
            indexer.closeFile();
            return true;
        } else {
            cout << "Error: Could not create file" << endl;
            return false;
        }
    }
}

bool handleGetWord(FileIndexer& indexer) {
    if (!indexer.openFile()) {
        cout << "Error: Could not open file for reading." << endl;
        return false;
    }

    long wordCount = indexer.getWordCount();
    if (wordCount == 0) {
        cout << "File is empty or could not read word count." << endl;
        indexer.closeFile();
        return false;
    }

    long index;
    cout << "Enter word index (0 to " << wordCount - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < wordCount) {
        string word = indexer[index];
        cout << "Word at index " << index << ": '" << word << "'" << endl;
        indexer.closeFile();
        return true;
    } else {
        cout << "Error: Invalid index. Must be between 0 and " << wordCount - 1 << endl;
        indexer.closeFile();
        return false;
    }
}

bool handleShowWordCount(FileIndexer& indexer) {
    if (indexer.openFile()) {
        cout << "Total words in file: " << indexer.getWordCount() << endl;
        indexer.closeFile();
        return true;
    } else {
        cout << "Error: Could not open file for reading." << endl;
        return false;
    }
}

bool handleWriteWord(FileIndexer& indexer) {
    string word;
    cout << "Enter word to write: ";
    getline(cin, word);

    if (indexer.writeWord(word)) {
        cout << "Word '" << word << "' successfully written to file!" << endl;
        return true;
    } else {
        cout << "Error: Could not write word to file." << endl;
        return false;
    }
}

bool handleChoice(FileIndexer& indexer, const std::string& filename, int choice) {
    switch (choice) {
        case 1:
            handleOpenFile(indexer, filename);
            break;
        case 2:
            handleGetWord(indexer);
            break;
        case 3:
            handleShowWordCount(indexer);
            break;
        case 4:
            handleWriteWord(indexer);
            break;
        case 5:
            return false;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
    return true;
}