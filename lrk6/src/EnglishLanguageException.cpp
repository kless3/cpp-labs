#include "../include/EnglishLanguageException.h"

EnglishLanguageException::EnglishLanguageException(const std::string& text)
        : std::invalid_argument("Текст содержит не русские символы: " + text) {}