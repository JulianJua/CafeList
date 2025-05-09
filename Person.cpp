#include "Person.h"
#include <iostream>

Person::Person(std::string name, std::string id) {
    this->name = name;
    this->id = id;
}

void Person::display() const {
    std::cout << "Name: " << name << ", ID: " << id << std::endl;
}
