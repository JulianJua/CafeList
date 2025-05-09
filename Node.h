#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
private:
    std::string data;
    Node* next;
    Node* prev;

public:
    Node();
    Node(const std::string& w);

    std::string getData() const;
    Node* getNext() const;
    Node* getPrev() const;

    void setData(const std::string& w);
    void setNext(Node* n);
    void setPrev(Node* p);
};

bool operator == (const Node& lhs, const Node& rhs);

bool operator < (const Node& lhs, const Node& rhs);

bool operator > (const Node& lhs, const Node& rhs);

bool operator <= (const Node& lhs, const Node& rhs);

bool operator >= (const Node& lhs, const Node& rhs);

bool operator != (const Node& lhs, const Node& rhs);



bool operator==(const Node& node, const std::string& str);

bool operator!=(const Node& node, const std::string& str);

bool operator<(const Node& node, const std::string& str);

bool operator>(const Node& node, const std::string& str);

bool operator<=(const Node& node, const std::string& str);

bool operator>=(const Node& node, const std::string& str);


bool operator==(const std::string& str, const Node& node);

bool operator!=(const std::string& str, const Node& node);

bool operator<(const std::string& str, const Node& node);

bool operator>(const std::string& str, const Node& node);

bool operator<=(const std::string& str, const Node& node);

bool operator>=(const std::string& str, const Node& node);

#endif
