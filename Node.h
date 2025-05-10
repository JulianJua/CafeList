#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;

public:
    Node(T value);
    void setData(T value);
    void setNext(Node<T>* nextNode);
    T getData() const;
    Node<T>* getNext() const;
};

#include "Node.cpp" // Needed because it's a template
#endif
