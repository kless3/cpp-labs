#pragma once

#include "FileAccessFailedException.h"

class FileSaveFailedException : public FileAccessFailedException {
public:
    explicit FileSaveFailedException(const std::string& filename);
};

