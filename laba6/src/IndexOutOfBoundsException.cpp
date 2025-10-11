#include "../include/IndexOutOfBoundsException.h"
#include <sstream>

std::string IndexOutOfBoundsException::createMessage(int index, int size) {
    std::ostringstream message;
    message << "Index " << index << " is out of bounds for array of size " << size;
    return message.str();
}

IndexOutOfBoundsException::IndexOutOfBoundsException(int index, int size)
        : std::out_of_range(createMessage(index, size)) {}


