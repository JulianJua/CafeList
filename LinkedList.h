#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

struct LinkedList {
private:
    Node* head;
    Node* tail;
    int listSize;
    
    void setHead(Node* newHead);
    void setTail(Node* newTail);
    void setListSize(int newListSize);

public:
    LinkedList(); 
    void clear();
    ~LinkedList();              
    LinkedList(const std::string& firstWord);  

    void push_back(const std::string& word);  
    void push_back(Node* addNode); 

    int size() const;                        

    Node* getHead() const;
    Node* getTail() const;
    Node* deleteWord(Node* target);
    Node* insert_before(const std::string& addWord, Node* knownNode);
    LinkedList& operator+=(LinkedList& rhs);
    void mergeSort();                         
    void mergeSort(LinkedList* topListPtr);   

};

#endif
