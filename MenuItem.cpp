#include "MenuItem.h"

MenuItem::MenuItem(std::string name, double price, bool available) {
    this->name = name;
    this->price = price;
    this->available = available;
}

std::string MenuItem::getName() const {
    return name;
}

double MenuItem::getPrice() const {
    return price;
}

bool MenuItem::isAvailable() const {
    return available;
}
