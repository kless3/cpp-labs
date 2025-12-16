#pragma once

#include "TaskParseFailedException.h"

class InvalidTaskFormatException : public TaskParseFailedException {
public:
    explicit InvalidTaskFormatException(const std::string& details);
};

