#ifndef FILEINDEXER_H
#define FILEINDEXER_H

#include <string>

class FileIndexer {
private:
    std::string filename;
    FILE* file = nullptr;
    long fileSize = 0;
    long wordCount = 0;

    bool isWhitespace(char c) const;
    long calculateWordCount();
    long findWordPosition(long wordIndex);

public:
    explicit FileIndexer(const std::string& filename);
    ~FileIndexer();

    // Delete copy operations
    FileIndexer(const FileIndexer&) = delete;
    FileIndexer& operator=(const FileIndexer&) = delete;

    // Custom move operations
    FileIndexer(FileIndexer&& other) noexcept;
    FileIndexer& operator=(FileIndexer&& other) noexcept;

    bool openFile();
    bool openFileForWrite();
    void closeFile();
    std::string operator[](long wordIndex);
    bool writeWord(const std::string& word);
    long getWordCount() const;
};

#endif