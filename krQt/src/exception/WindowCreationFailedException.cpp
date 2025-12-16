#include "exceptions/WindowCreationFailedException.h"

WindowCreationFailedException::WindowCreationFailedException(const std::string& windowName)
    : AppException("Failed to create window: " + windowName)
{
}

