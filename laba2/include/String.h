#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class String {
private:
    char *data;
    size_t length = 0;

    void copyFrom(const char *str, size_t len);

public:
    String();

    explicit String(const char *str);

    String(const String &other);

    ~String();

    bool operator!() const;

    String operator()(int start, int count) const;

    char &operator[](int index);

    const char &operator[](int index) const;

    friend std::ostream &operator<<(std::ostream &os, const String &str) {
        os << str.data;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, String &str) {
        std::string buffer;
        std::getline(is, buffer);

        delete[] str.data;
        str.length = buffer.length();
        str.data = new char[str.length + 1];
        std::copy(buffer.begin(), buffer.end(), str.data);
        str.data[str.length] = '\0';

        return is;
    }
};

#endif