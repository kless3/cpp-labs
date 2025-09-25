#ifndef SEARCH_H
#define SEARCH_H

template <typename T>
int sequentialSearch(const T array[], int size, const T& key) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

#endif