#ifndef NODE_H
#define NODE_H

template <typename T>
class [[maybe_unused]] Node {
public:
    T data;
    [[maybe_unused]] Node<T>* next;

    explicit Node(const T& value);
};

template<typename T>
Node<T>::Node(const T &value) : data(value), next(nullptr) {}

#endif