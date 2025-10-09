#include "../include/EnglishLanguageException.h"

EnglishLanguageException::EnglishLanguageException(const std::string& text)
        : std::invalid_argument("Text contains non-English characters: " + text) {}