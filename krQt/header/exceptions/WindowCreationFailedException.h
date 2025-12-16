#pragma once

#include "AppException.h"

class WindowCreationFailedException : public AppException {
public:
    explicit WindowCreationFailedException(const std::string& windowName);
};

