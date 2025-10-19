#ifndef FILEINDEXER_H
#define FILEINDEXER_H

#include <string>

class FileIndexer {
private:
    std::string filename;
    FILE* file;
    long fileSize;
    long wordCount;

    bool isWhitespace(char c);
    long calculateWordCount();
    long findWordPosition(long wordIndex);

public:
    explicit FileIndexer(const std::string& filename);
    ~FileIndexer();

    // Delete copy operations
    FileIndexer(const FileIndexer&) = delete;
    FileIndexer& operator=(const FileIndexer&) = delete;

    // Default move operations
    FileIndexer(FileIndexer&&) = default;
    FileIndexer& operator=(FileIndexer&&) = default;

    bool openFile();
    bool openFileForWrite();
    void closeFile();
    std::string operator[](long wordIndex);
    bool writeWord(const std::string& word);
    long getWordCount() const;
};

#endif