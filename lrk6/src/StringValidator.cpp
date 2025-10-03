#include "../include/StringValidator.h"
#include "../include/EnglishLanguageException.h"
#include <regex>

bool StringValidator::isEnglishText(const std::string& text) {
    if (text.empty()) return true;

    std::regex englishRegex(R"(^[a-zA-Z\s\d\p{Punct}]*$)");
    return std::regex_match(text, englishRegex);
}

void StringValidator::validateEnglishText(const std::string& text) {
    if (!isEnglishText(text)) {
        throw EnglishLanguageException(text);
    }
}