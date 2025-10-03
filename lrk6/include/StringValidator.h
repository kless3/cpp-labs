#ifndef STRINGVALIDATOR_H
#define STRINGVALIDATOR_H

#include <string>

class StringValidator {
public:
    static bool isEnglishText(const std::string& text);
    static void validateEnglishText(const std::string& text);
};

#endif