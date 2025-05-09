#include "Node.h"
using namespace std;

Node::Node() {
    this->data = "";
    this->next = nullptr;
    this->prev = nullptr;
}

Node::Node(const string& w) {
    this->data = w;
    this->next = nullptr;
    this->prev = nullptr;
}

string Node::getData() const {
    return this->data;
}

Node* Node::getNext() const {
    return this->next;
}

Node* Node::getPrev() const {
    return this->prev;
}

void Node::setData(const string& w) {
    this->data = w;
}

void Node::setNext(Node* n) {
    this->next = n;
}

void Node::setPrev(Node* p) {
    this->prev = p;
}

bool operator==(const Node& lhs, const Node& rhs) {
    return (lhs.getData() == rhs.getData());
}

bool operator<(const Node& lhs, const Node& rhs) {
   return lhs.getData() < rhs.getData();
}

bool operator>(const Node& lhs, const Node& rhs) {
   return rhs < lhs;
}

bool operator<=(const Node& lhs, const Node& rhs) {
   return !(lhs > rhs);
}

bool operator>=(const Node& lhs, const Node& rhs) {
   return !(lhs < rhs); 
}

bool operator!=(const Node& lhs, const Node& rhs) {
   return !(lhs == rhs);
}


bool operator==(const Node& node, const string& str) { 
   return node.getData() == str; 
}

bool operator!=(const Node& node, const string& str) { 
   return node.getData() != str; 
}

bool operator<(const Node& node, const string& str) { 
   return node.getData() <  str; 
}

bool operator>(const Node& node, const string& str) { 
   return node.getData() >  str; 
}

bool operator<=(const Node& node, const string& str) { 
   return node.getData() <= str; 
}

bool operator>=(const Node& node, const string& str) {
   return node.getData() >= str; 
}

bool operator==(const string& str, const Node& node) { 
   return str == node.getData();
}

bool operator!=(const string& str, const Node& node) { 
   return str != node.getData(); 
}

bool operator<(const string& str, const Node& node) { 
   return str <  node.getData(); 
}

bool operator>(const string& str, const Node& node) { 
   return str >  node.getData(); 
}

bool operator<=(const string& str, const Node& node) {
   return str <= node.getData(); 
}

bool operator>=(const string& str, const Node& node) {
   return str >= node.getData(); 
}
