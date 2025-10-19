#include "../include/FileIndexer.h"
#include <cstdio>
#include <cctype>
#include <utility>

FileIndexer::FileIndexer(const std::string& filename)
        : filename(filename) {
}

FileIndexer::~FileIndexer() {
    closeFile();
}

// Move constructor
FileIndexer::FileIndexer(FileIndexer&& other) noexcept
        : filename(std::move(other.filename)),
          file(other.file),
          fileSize(other.fileSize),
          wordCount(other.wordCount) {
    other.file = nullptr;
    other.fileSize = 0;
    other.wordCount = 0;
}

// Move assignment operator
FileIndexer& FileIndexer::operator=(FileIndexer&& other) noexcept {
    if (this != &other) {
        closeFile();

        filename = std::move(other.filename);
        file = other.file;
        fileSize = other.fileSize;
        wordCount = other.wordCount;

        other.file = nullptr;
        other.fileSize = 0;
        other.wordCount = 0;
    }
    return *this;
}

bool FileIndexer::isWhitespace(char c) const {
    return std::isspace(static_cast<unsigned char>(c));
}

bool FileIndexer::openFile() {
    file = fopen(filename.c_str(), "rb");
    if (!file) {
        return false;
    }

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    wordCount = calculateWordCount();
    return true;
}

bool FileIndexer::openFileForWrite() {
    file = fopen(filename.c_str(), "ab");
    if (!file) {
        return false;
    }
    return true;
}

void FileIndexer::closeFile() {
    if (file) {
        fclose(file);
        file = nullptr;
    }
}

long FileIndexer::calculateWordCount() {
    if (!file || fileSize == 0) {
        return 0;
    }

    long count = 0;
    bool inWord = false;
    std::string buffer(1024, '\0');

    fseek(file, 0, SEEK_SET);

    size_t bytesRead;
    while ((bytesRead = fread(&buffer[0], 1, buffer.size(), file)) > 0) {
        for (size_t i = 0; i < bytesRead; ++i) {
            if (bool currentIsWhitespace = isWhitespace(buffer[i]); currentIsWhitespace && inWord) {
                count++;
                inWord = false;
            } else if (!currentIsWhitespace) {
                inWord = true;
            }
        }
    }

    if (inWord) {
        count++;
    }

    fseek(file, 0, SEEK_SET);
    return count;
}

long FileIndexer::findWordPosition(long wordIndex) {
    if (!file || wordIndex < 0 || wordIndex >= wordCount) {
        return -1;
    }

    long currentWord = 0;
    long position = 0;
    bool inWord = false;
    char c;

    fseek(file, 0, SEEK_SET);

    while (currentWord <= wordIndex && position < fileSize) {
        if (fread(&c, 1, 1, file) != 1) {
            break;
        }

        bool currentIsWhitespace = isWhitespace(c);

        if (currentIsWhitespace && inWord) {
            currentWord++;
            inWord = false;
            if (currentWord > wordIndex) {
                return position;
            }
        } else if (!currentIsWhitespace) {
            if (!inWord && currentWord == wordIndex) {
                return position;
            }
            inWord = true;
        }

        position++;
    }

    return (inWord && currentWord == wordIndex) ? position : -1;
}

std::string FileIndexer::operator[](long wordIndex) {
    if (!file || wordIndex < 0 || wordIndex >= wordCount) {
        return "";
    }

    long wordStart = findWordPosition(wordIndex);
    if (wordStart == -1) {
        return "";
    }

    std::string word;
    char c;
    bool readingWord = false;

    fseek(file, wordStart, SEEK_SET);

    while (fread(&c, 1, 1, file) == 1) {
        if (isWhitespace(c)) {
            if (readingWord) {
                break;
            }
        } else {
            word += c;
            readingWord = true;
        }
    }

    return word;
}

bool FileIndexer::writeWord(const std::string& word) {
    if (!file && !openFileForWrite()) {
        return false;
    }

    if (std::string spaceWord = " " + word;
            fwrite(spaceWord.c_str(), 1, spaceWord.size(), file) != spaceWord.size()) {
        return false;
    }

    fflush(file);
    return true;
}

long FileIndexer::getWordCount() const {
    return wordCount;
}