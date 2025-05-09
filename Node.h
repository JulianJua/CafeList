#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data;
    Node* next;

public:
    Node(T value);
    void setData(T value);
    void setNext(Node* nextNode);
    T getData() const;
    Node* getNext() const;
};

template <typename T>
Node<T>::Node(T value) {
    data = value;
    next = nullptr;
}

template <typename T>
void Node<T>::setData(T value) {
    data = value;
}

template <typename T>
void Node<T>::setNext(Node* nextNode) {
    next = nextNode;
}

template <typename T>
T Node<T>::getData() const {
    return data;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

#endif
