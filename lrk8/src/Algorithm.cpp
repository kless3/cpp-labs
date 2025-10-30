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
void Algorithm<T>::selectionSort(Deque<T>& deque) {
    int n = deque.getSize();
    if (n <= 1) return;

    auto arr = new T[n];
    auto it = deque.getIterator();
    for (int i = 0; i < n; i++) {
        arr[i] = it.getValue();
        it.next();
    }

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    deque.clear();
    for (int i = 0; i < n; i++) {
        deque.enqueueRear(arr[i]);
    }

    delete[] arr;
}

template class Algorithm<int>;
template class Algorithm<double>;
template class Algorithm<char>;
template class Algorithm<std::string>;