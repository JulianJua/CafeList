#include "Menu.h"
#include <iostream>

void Menu::addItems(MenuItem* item) {
    items.addBack(item);
}

bool Menu::removeItems(std::string name) {
    return items.remove(name);
}

MenuItem* Menu::searchItems(std::string name) {
    return items.search(name);
}

void Menu::sortByPrice() {
    items.sortByPrice();
}

void Menu::displayMenu() {
    items.displayAll();
}
