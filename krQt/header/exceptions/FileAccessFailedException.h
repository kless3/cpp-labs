#pragma once

#include "AppException.h"

class FileAccessFailedException : public AppException {
public:
    explicit FileAccessFailedException(const std::string& filename, const std::string& operation);
};

