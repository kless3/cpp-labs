#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* next = nullptr;
    Node* prev = nullptr;
    explicit Node(const T& value) : data(value) {}
};

#endif