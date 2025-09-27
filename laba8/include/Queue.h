#ifndef QUEUE_H
#define QUEUE_H

class Node {
public:
    int data;
    Node* next;
    Node(int value);
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
    bool isEmpty() const;
    int getSize() const;
    void clear();
    void display() const;

    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* start);
        void next();
        bool hasNext() const;
        int getValue() const;
    };

    Iterator getIterator() const;
};

class Algorithm {
public:
    static int linearSearch(const Queue& queue, int target);
    static void bubbleSort(Queue& queue);
};

#endif