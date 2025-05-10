#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList();
    ~LinkedList();

    void addBack(T value);
    bool remove(std::string name);
    T search(std::string name) const;
    void sortByPrice();
    void displayAll() const;
    void clear();
};

#include "LinkedList.tpp"
#endif
