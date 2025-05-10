#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::addBack(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

template <typename T>
bool LinkedList<T>::remove(std::string name) {
    Node<T>* current = head;
    Node<T>* prev = nullptr;

    while (current != nullptr) {
        if (current->getData()->getName() == name) {
            if (prev == nullptr) {
                head = current->getNext();
            } else {
                prev->setNext(current->getNext());
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->getNext();
    }
    return false;
}

template <typename T>
T LinkedList<T>::search(std::string name) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->getData()->getName() == name) {
            return current->getData();
        }
        current = current->getNext();
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::sortByPrice() {
    if (head == nullptr || head->getNext() == nullptr) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node<T>* current = head;
        while (current->getNext() != nullptr) {
            if (current->getData()->getPrice() > current->getNext()->getData()->getPrice()) {
                T temp = current->getData();
                current->setData(current->getNext()->getData());
                current->getNext()->setData(temp);
                swapped = true;
            }
            current = current->getNext();
        }
    } while (swapped);
}

template <typename T>
void LinkedList<T>::displayAll() const {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->getData()->getName()
                  << " - $" << current->getData()->getPrice() << std::endl;
        current = current->getNext();
    }
}

template <typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
}
