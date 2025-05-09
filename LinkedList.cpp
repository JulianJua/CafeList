#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->listSize = 0;
}

void LinkedList::clear() {
    Node* dataNow = head;
    while (dataNow != nullptr) {
        Node* nextNode = dataNow->getNext();
        delete dataNow;
        dataNow = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push_back(const string& word) {
    Node* newNode = new Node(word);
    if (this->head == nullptr) {
        this->head = this->tail = newNode;
    } else {
        this->tail->setNext(newNode);
        newNode->setPrev(this->tail);
        this->tail = newNode;
    }
    this->listSize++;
}

void LinkedList::push_back(Node* addNode) {
    if (addNode == nullptr) return;

    addNode->setNext(nullptr); 
    addNode->setPrev(tail);    

    if (tail != nullptr) {
        tail->setNext(addNode); 
    } else {
        head = addNode; 
    }

    tail = addNode;     
    listSize++;
}


LinkedList::LinkedList(const string& firstWord) {
    this->head = nullptr;
    this->tail = nullptr;
    this->listSize = 0;
    this->push_back(firstWord);
}


int LinkedList::size() const {
    return this->listSize;
}

Node* LinkedList::getHead() const {
    return this->head;
}

Node* LinkedList::getTail() const {
    return this->tail;
}

void LinkedList::setHead(Node* newHead) {
    this->head = newHead;
}

void LinkedList::setTail(Node* newTail) {
    this->tail = newTail;
}

void LinkedList::setListSize(int newListSize) {
    this->listSize = newListSize;
}

Node* LinkedList::deleteWord(Node* target) {
    if (target == nullptr) {
        return nullptr;
    }

    Node* nextNode = target->getNext();
    Node* prevNode = target->getPrev();

    if (target == head) {
        head = nextNode;
    }

    if (target == tail) {
        tail = prevNode;
    }

    if (prevNode != nullptr) {
        prevNode->setNext(nextNode);
    }
    if (nextNode != nullptr) {
        nextNode->setPrev(prevNode);
    }

    delete target;
    listSize--;

    return nextNode;
}

Node* LinkedList::insert_before(const std::string& addWord, Node* knownNode) {
    Node* newNode = new Node(addWord);

    if (knownNode == head || head == nullptr) {
        newNode->setNext(knownNode);
        newNode->setPrev(nullptr);

        if (knownNode != nullptr) {
            knownNode->setPrev(newNode);
        }

        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }

        listSize++;
        return newNode;
    }

    Node* prevNode = knownNode->getPrev();
    newNode->setNext(knownNode);
    newNode->setPrev(prevNode);

    if (prevNode != nullptr) {
        prevNode->setNext(newNode);
    }

    knownNode->setPrev(newNode);
    listSize++;

    return newNode;
}

LinkedList& LinkedList::operator+=(LinkedList& rhs) {
    if (this == &rhs) return *this; 

    Node* current = rhs.head;
    while (current != nullptr) {
        Node* next = current->getNext(); 
        current->setPrev(nullptr);
        current->setNext(nullptr);

        this->push_back(current);

        current = next;
    }

    
    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.listSize = 0;

    return *this;
}
void LinkedList::mergeSort() {
    mergeSort(this);
}

void LinkedList::mergeSort(LinkedList* topListPtr) {
    if (topListPtr == nullptr || topListPtr->size() <= 1) {
        return;
    }

    LinkedList* leftList = new LinkedList;
    LinkedList* rightList = new LinkedList;

    int mid = topListPtr->size() / 2;
    Node* currentNode = topListPtr->getHead();

    for (int i = 0; i < mid; i++) {
        leftList->push_back(new Node(currentNode->getData()));
        currentNode = currentNode->getNext();
    }

    while (currentNode != nullptr) {
        rightList->push_back(new Node(currentNode->getData()));
        currentNode = currentNode->getNext();
    }

    mergeSort(leftList);
    mergeSort(rightList);

    topListPtr->clear();
    topListPtr->mergeDicts(leftList);
    topListPtr->mergeDicts(rightList);

    delete leftList;
    leftList = nullptr;

    delete rightList;
    rightList = nullptr;
}
