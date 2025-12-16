#pragma once

#include "TaskParseFailedException.h"

class NumericConversionFailedException : public TaskParseFailedException {
public:
    explicit NumericConversionFailedException(const std::string& fieldName);
};

