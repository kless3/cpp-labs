#pragma once

#include "AppException.h"

class TaskParseFailedException : public AppException {
public:
    explicit TaskParseFailedException(const std::string& reason);
};

