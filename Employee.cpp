#include "Employee.h"
#include <iostream>

Employee::Employee(std::string name, std::string id, std::string workID, std::string workUniform)
    : Person("", "") // this line is now removed
{
    this->name = name;
    this->id = id;
    this->workID = workID;
    this->workUniform = workUniform
}

void Employee::clockIn() const {
    std::cout << name << " clocked in wearing uniform: " << workUniform << std::endl;
}
