#ifndef ENGLISHLANGUAGEEXCEPTION_H
#define ENGLISHLANGUAGEEXCEPTION_H

#include <stdexcept>
#include <string>

class EnglishLanguageException : public std::invalid_argument {
public:
    explicit EnglishLanguageException(const std::string& text);
};

#endif