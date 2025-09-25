#ifndef SEARCH_H
#define SEARCH_H

#include <span>

template <typename T>
int sequentialSearch(std::span<const T> array, const T& key) {
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

#endif