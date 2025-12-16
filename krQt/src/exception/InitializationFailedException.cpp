#include "exceptions/InitializationFailedException.h"

InitializationFailedException::InitializationFailedException(const std::string& component)
    : AppException("Failed to initialize: " + component)
{
}

