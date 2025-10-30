#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Deque.h"

template <typename T>
class Algorithm {
public:
    static int linearSearch(const Deque<T>& deque, const T& target);
    static void selectionSort(Deque<T>& deque);
};


#endif