#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

template <typename T>
Node<T>::Node(T value) {
    this->data = value;
    this->next = nullptr;
}

template <typename T>
void Node<T>::setData(T value) {
    this->data = value;
}

template <typename T>
void Node<T>::setNext(Node<T>* nextNode) {
    this->next = nextNode;
}

template <typename T>
T Node<T>::getData() const {
    return this->data;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return this->next;
}

#endif
