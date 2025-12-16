#pragma once

#include "AppException.h"

class InitializationFailedException : public AppException {
public:
    explicit InitializationFailedException(const std::string& component);
};

