#include "../include/Menu.h"
#include <iostream>
#include <utility>

using namespace std;

Menu::Menu(const std::string& filename)
        : filename(filename) {
    indexer = new FileIndexer(filename);
}

Menu::~Menu() {
    delete indexer;
}

// Move constructor
Menu::Menu(Menu&& other) noexcept
        : filename(std::move(other.filename)),
          indexer(other.indexer) {
    other.indexer = nullptr;
}

// Move assignment operator
Menu& Menu::operator=(Menu&& other) noexcept {
    if (this != &other) {
        delete indexer; // Delete current indexer

        filename = std::move(other.filename);
        indexer = other.indexer;

        other.indexer = nullptr;
    }
    return *this;
}

void Menu::printMenu() {
    cout << "\n=== File Indexer Menu ===" << endl;
    cout << "1. Open file and count words" << endl;
    cout << "2. Get word by index" << endl;
    cout << "3. Show total word count" << endl;
    cout << "4. Write word to file" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose option: ";
}

void Menu::handleOpenFile() {
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
}

void Menu::handleGetWord() {
    if (!indexer->openFile()) {
        cout << "Error: Could not open file for reading." << endl;
        return;
    }

    long wordCount = indexer->getWordCount();
    if (wordCount == 0) {
        cout << "File is empty or could not read word count." << endl;
        indexer->closeFile();
        return;
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
}

void Menu::handleShowWordCount() {
    if (indexer->openFile()) {
        cout << "Total words in file: " << indexer->getWordCount() << endl;
        indexer->closeFile();
    } else {
        cout << "Error: Could not open file for reading." << endl;
    }
}

void Menu::handleWriteWord() {
    string word;
    cout << "Enter word to write: ";
    getline(cin, word);

    if (indexer->writeWord(word)) {
        cout << "Word '" << word << "' successfully written to file!" << endl;
    } else {
        cout << "Error: Could not write word to file." << endl;
    }
}

bool Menu::handleChoice(int choice) {
    switch (choice) {
        case 1: handleOpenFile(); break;
        case 2: handleGetWord(); break;
        case 3: handleShowWordCount(); break;
        case 4: handleWriteWord(); break;
        case 5: return false;
        default: cout << "Invalid choice. Please try again." << endl;
    }
    return true;
}