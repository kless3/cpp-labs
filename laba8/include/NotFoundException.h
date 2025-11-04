//
// Created by Maksim on 04.11.2025.
//

#ifndef LABA8_NOTFOUNDEXCEPTION_H
#define LABA8_NOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <string>

class NotFoundException : public std::runtime_error {
public:
    explicit NotFoundException(const std::string& message);
};

#endif //LABA8_NOTFOUNDEXCEPTION_H