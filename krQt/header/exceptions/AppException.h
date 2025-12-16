#pragma once

#include <exception>
#include <string>

class AppException : public std::exception {
public:
    explicit AppException(const std::string& message);
    const char* what() const noexcept override;

protected:
    std::string message;
};

