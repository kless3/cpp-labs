#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

template <typename T>
class Iterator {
private:
    Node<T>* current = nullptr;

public:
    explicit Iterator(Node<T>* start) : current(start) {}

    void next() {
        if (current != nullptr) {
            current = current->next;
        }
    }

    [[nodiscard]] bool hasNext() const {
        return current != nullptr;
    }

    [[nodiscard]] T getValue() const {
        return current->data;
    }
};

#endif