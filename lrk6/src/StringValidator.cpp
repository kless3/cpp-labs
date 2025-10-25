#include "../include/StringValidator.h"
#include "../include/EnglishLanguageException.h"
#include <regex>

bool StringValidator::isEnglishText(const std::string& text) {
    if (text.empty()) return false;

    std::regex englishRegex(R"([a-zA-Z])");
    return std::regex_search(text, englishRegex);
}

void StringValidator::validateEnglishText(const std::string& text) {
    if (isEnglishText(text)) {
        throw EnglishLanguageException(text);
    }
}