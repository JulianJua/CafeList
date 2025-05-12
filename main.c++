#include <iostream>
#include "LinkedList.h"
#include "MenuItem.h"
#include "Food.h"
#include "Beverage.h"
#include "Menu.h"  
#include <string>

using namespace std;

// ========== Main ==========

int main() {
    Menu cafeMenu;
    
    cafeMenu.loadFromFile("menu.txt");
    
    LinkedList<MenuItem*>& masterMenu = cafeMenu.getItems();  
    
    LinkedList<MenuItem*> userOrder;

    
    cafeMenu.saveToFile("menu_updated.txt");
    
    return 0;
}