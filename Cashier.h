#ifndef CASHIER_H
#define CASHIER_H

#include "Employee.h"

class Cashier : public Employee {
private:
    double reg;

public:
    Cashier(std::string name, std::string id, std::string workID,
            std::string workUniform, double reg);

    void processPayment() const;
    void giveReceipt() const;
};

#endif
