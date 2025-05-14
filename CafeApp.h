#ifndef CAFEAPP_H
#define CAFEAPP_H

#include "LinkedList.h"
#include "MenuItem.h"
#include "Menu.h"
#include <string>

class CafeApp {
private:
    Menu cafeMenu;
    LinkedList<MenuItem*> userOrder;
    
    LinkedList<std::string> hotDrinks;
    LinkedList<std::string> coldDrinks;
    LinkedList<std::string> nonCaff;
    LinkedList<std::string> pastries;
    LinkedList<std::string> sandwiches;
    LinkedList<std::string> snacks;
    
    void displayMainMenu();
    void displayBeverageOptions();
    void displayFoodOptions();
    void displayItemChoices(LinkedList<std::string>& items);
    
    void handleBeverages();
    void handleFood();
    void checkout();
    
    void initializeCategoryLists();
    
public:
    CafeApp();
    void run();
};

#endif