#ifndef QUEUE_H
#define QUEUE_H

class Node {
public:
    int data;
    Node* next;
    explicit Node(int value);
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue();
    ~Queue();
    void enqueue(int value);
    int dequeue();
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] int getSize() const;
    void clear();
    void display() const;

    class Iterator {
    private:
        Node* current;
    public:
        explicit Iterator(Node* start);
        void next();
        [[nodiscard]] bool hasNext() const;
        [[nodiscard]] int getValue() const;
    };

    [[nodiscard]] Iterator getIterator() const;
};

class Algorithm {
public:
    static int linearSearch(const Queue& queue, int target);
    static void bubbleSort(Queue& queue);
};

#endif