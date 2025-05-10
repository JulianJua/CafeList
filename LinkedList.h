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
    
    // Added methods
    Node<T>* getHead() const { return head; }
    
    class Iterator {
    private:
        Node<T>* current;
    
    public:
        Iterator(Node<T>* start) : current(start) {}
        
        bool hasNext() const {
            return current != nullptr;
        }
        
        T next() {
            T data = current->getData();
            current = current->getNext();
            return data;
        }
    };
    
   Iterator begin() const {
        return Iterator(head);
}
    
    T get(int index) const {
        Node<T>* current = head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->getNext();
        }
        if (current == nullptr) {
            return T(); // Return default value if index is out of bounds
        }
        return current->getData();
    }
};

#include "LinkedList.tpp"
#endif