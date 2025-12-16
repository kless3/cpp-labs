#pragma once

#include "FileAccessFailedException.h"

class FileOpenFailedException : public FileAccessFailedException {
public:
    explicit FileOpenFailedException(const std::string& filename);
};

