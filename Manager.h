#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include "LinkedList.h"

class Manager : public Employee {
private:
    std::string department;
    LinkedList<Employee*> team;

public:
    Manager(std::string name, std::string id, std::string workID,
            std::string workUniform, std::string department);

    void workSchedule() const;
    void hireEmployee(Employee* newEmp);
    void displayTeam() const;
};

#endif
