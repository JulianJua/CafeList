#ifndef MENU_H
#define MENU_H

#include "LinkedList.h"
#include "MenuItem.h"

class Menu {
private:
    LinkedList<MenuItem*> items;

public:
    void addItems(MenuItem* item);
    bool removeItems(std::string name);
    MenuItem* searchItems(std::string name);
    void sortByPrice();
    void displayMenu();
};

#endif
