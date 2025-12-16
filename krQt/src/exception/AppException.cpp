#include "exceptions/AppException.h"

AppException::AppException(const std::string& message)
    : message(message)
{
}

const char* AppException::what() const noexcept {
    return message.c_str();
}

