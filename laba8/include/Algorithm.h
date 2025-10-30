#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Queue.h"

template <typename T>
class Algorithm {
public:
    static int linearSearch(const Queue<T>& queue, const T& target);
    static void selectionSort(Queue<T>& queue);
};

#endif