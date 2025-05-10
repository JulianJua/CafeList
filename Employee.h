#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
protected:
    std::string workID;
    std::string workUniform;

public:
    Employee(std::string name, std::string id, std::string workID, std::string workUniform);
    virtual void clockIn() const;
};

#endif
