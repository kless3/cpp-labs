#ifndef ALGORITHM_CPP
#define ALGORITHM_CPP

#include "../include/Algorithm.h"

template <typename T>
int Algorithm<T>::linearSearch(const Deque<T>& deque, const T& target) {
    auto it = deque.getIterator();
    int index = 0;
    while (it.hasNext()) {
        if (it.getValue() == target) {
            return index;
        }
        it.next();
        index++;
    }
    return -1;
}

template <typename T>
void Algorithm<T>::bubbleSort(Deque<T>& deque) {
    int n = deque.getSize();
    if (n <= 1) return;

    auto arr = new T[n];
    auto it = deque.getIterator();
    for (int i = 0; i < n; i++) {
        arr[i] = it.getValue();
        it.next();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    deque.clear();
    for (int i = 0; i < n; i++) {
        deque.enqueueRear(arr[i]);
    }

    delete[] arr;
}

#endif