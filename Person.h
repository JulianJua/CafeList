#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string name;
    std::string id;

public:
    Person(std::string name, std::string id);
    virtual void display() const;
};

#endif
