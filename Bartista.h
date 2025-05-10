#ifndef BARISTA_H
#define BARISTA_H

#include "Employee.h"

class Barista : public Employee {
private:
    int cups;

public:
    Barista(std::string name, std::string id, std::string workID,
            std::string workUniform, int cups);

    void makeDrinks() const;
    void brewCoffee() const;
};

#endif
