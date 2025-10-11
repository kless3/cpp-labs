#ifndef LABA6_INDEXOUTOFBOUNDSEXCEPTION_H
#define LABA6_INDEXOUTOFBOUNDSEXCEPTION_H

#include <stdexcept>

class IndexOutOfBoundsException : public std::out_of_range {
public:
    explicit IndexOutOfBoundsException(int index, int size);

    static std::string createMessage(int index, int size);
};

#endif
