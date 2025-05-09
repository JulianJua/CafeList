#include "Cashier.h"
#include <iostream>

Cashier::Cashier(std::string name, std::string id, std::string workID,
                 std::string workUniform, double reg)
    : Employee("", "", "", "") // removed
{
    this->name = name;
    this->id = id;
    this->workID = workID;
    this->workUniform = workUniform;
    this->reg = reg;
}

void Cashier::processPayment() const {
    std::cout << name << " is processing a payment at register $" << reg << "\n";
}

void Cashier::giveReceipt() const {
    std::cout << name << " is giving a receipt.\n";
}
