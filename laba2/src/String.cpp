#include "../include/String.h"

void String::copyFrom(const char *str, size_t len) {
    data = new char[len + 1];
    std::strcpy(data, str);
    length = len;
}

String::String() : data(new char[1]) {
    data[0] = '\0';
}

String::String(const char *str) : data(nullptr) {
    if (str) {
        length = std::strlen(str);
        copyFrom(str, length);
    } else {
        data = new char[1];
        data[0] = '\0';
    }
}

String::String(const String &other) : data(nullptr), length(other.length) {
    copyFrom(other.data, length);
}

String::~String() {
    delete[] data;
}

bool String::operator!() const {
    return length == 0;
}

String String::operator()(int start, int count) const {
    if (start < 0 || start >= static_cast<int>(length)) {
        throw std::out_of_range("Start index out of range");
    }
    if (count < 0) {
        throw std::invalid_argument("Count cannot be negative");
    }

    auto actualCount = static_cast<size_t>(count);
    if (start + count > static_cast<int>(length)) {
        actualCount = length - start;
    }

    auto subStr = new char[actualCount + 1];
    std::strncpy(subStr, data + start, actualCount);
    subStr[actualCount] = '\0';

    String result(subStr);
    delete[] subStr;
    return result;
}

char &String::operator[](int index) {
    if (index < 0 || index >= static_cast<int>(length)) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const char &String::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(length)) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}