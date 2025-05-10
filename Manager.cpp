#include "Manager.h"
#include <iostream>

Manager::Manager(std::string name, std::string id, std::string workID,
                 std::string workUniform, std::string department)
    : Employee("", "", "", "") // this line is now removed
{
    this->name = name;
    this->id = id;
    this->workID = workID;
    this->workUniform = workUniform;
    this->department = department;
}

void Manager::workSchedule() const {
    std::cout << "Manager " << name << " is reviewing the schedule for the " << department << " department.\n";
}

void Manager::hireEmployee(Employee* newEmp) {
    team.addBack(newEmp);
    std::cout << "Manager " << name << " hired: ";
    newEmp->display();
}

void Manager::displayTeam() const {
    std::cout << "\nTeam under Manager " << name << ":\n";
    typename LinkedList<Employee*>::Iterator it = team.begin();
    while (it.hasNext()) {
        Employee* emp = it.next();
        emp->display();
    }
}
