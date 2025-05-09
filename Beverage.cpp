#include "Beverage.h"

Beverage::Beverage(std::string name, double price, bool available,
                   std::string size, int temperature)
    : MenuItem("", 0.0, false)
{
    this->name = name;
    this->price = price;
    this->available = available;

    this->size = size;
    this->temperature = temperature;
}

std::string Beverage::getCategory() const {
    return "Beverage";
}

int Beverage::getTemp() const {
    return this->temperature;
}
