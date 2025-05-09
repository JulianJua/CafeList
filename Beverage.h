#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "MenuItem.h"

class Beverage : public MenuItem {
private:
    std::string size;
    int temperature;

public:
    Beverage(std::string name, double price, bool available,
             std::string size, int temperature);

    std::string getCategory() const override;
    int getTemp() const;
};

#endif
