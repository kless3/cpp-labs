#include "../include/String.h"
#include <string_view>
#include <iostream>

const size_t MAX_LENGTH = 4096;

namespace {
    size_t safeStrlen(const char *str) {
        if (!str) return 0;

        for (size_t i = 0; i < MAX_LENGTH; ++i) {
            if (str[i] == '\0') {
                return i;
            }
        }
        return MAX_LENGTH;
    }
}

void String::copyFrom(const char *str, size_t len) {
    data = new char[len + 1];
    if (str && len > 0) {
        std::copy(str, str + len, data);
    }
    data[len] = '\0';
    length = len;
}

String::String() : data(new char[1]) {
    data[0] = '\0';
}

String::String(const char *str)
        : data(nullptr),
          length(str ? safeStrlen(str) : 0) {
    if (str) {
        copyFrom(str, length);
    } else {
        data = new char[1];
        data[0] = '\0';
    }
}

[[maybe_unused]] String::String(const String &other)
        : data(nullptr), length(other.length) {
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
        std::cout << "Error: Start index out of range" << std::endl;
        return String();
    }
    if (count < 0) {
        std::cout << "Error: Count cannot be negative" << std::endl;
        return String();
    }

    auto actualCount = static_cast<size_t>(count);
    if (start + count > static_cast<int>(length)) {
        actualCount = length - start;
    }

    auto subStr = new char[actualCount + 1];
    std::copy(data + start, data + start + actualCount, subStr);
    subStr[actualCount] = '\0';

    String result(subStr);
    delete[] subStr;
    return result;
}

char &String::operator[](int index) {
    if (index < 0 || index >= static_cast<int>(length)) {
        std::cout << "Error: Index out of range" << std::endl;
        static char dummy = '\0';
        return dummy;
    }
    return data[index];
}

const char &String::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(length)) {
        std::cout << "Error: Index out of range" << std::endl;
        static char dummy = '\0';
        return dummy;
    }
    return data[index];
}

String &String::operator=(const String &other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        copyFrom(other.data, length);
    }
    return *this;
}

String::String(String &&other) noexcept
        : data(other.data), length(other.length) {
    other.data = nullptr;
    other.length = 0;
}

String &String::operator=(String &&other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}