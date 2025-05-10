#include "Barista.h"
#include <iostream>

Barista::Barista(std::string name, std::string id, std::string workID,
                 std::string workUniform, int cups)
    : Employee("", "", "", "") // removed
{
    this->name = name;
    this->id = id;
    this->workID = workID;
    this->workUniform = workUniform;
    this->cups = cups;
}

void Barista::makeDrinks() const {
    std::cout << name << " is making " << cups << " drinks.\n";
}

void Barista::brewCoffee() const {
    std::cout << name << " is brewing coffee.\n";
}
