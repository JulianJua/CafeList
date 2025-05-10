#include <iostream>
#include <string>
#include "LinkedList.h"
#include "MenuItem.h"
#include "Beverage.h"
#include "Food.h"

using namespace std;

void testLinkedListAdd();
void testLinkedListRemove();
void testLinkedListSearch();

int main() {
    cout << "===== Running LinkedList Tests =====" << endl;
    
    testLinkedListAdd();
    testLinkedListRemove();
    testLinkedListSearch();
    
    cout << "All LinkedList tests completed." << endl;
    return 0;
}

void testLinkedListAdd() {
    cout << "Testing LinkedList::addBack... ";
    
    LinkedList<int> list;
    list.addBack(10);
    list.addBack(20);
    list.addBack(30);
    
    Node<int>* current = list.getHead();
    
    if (current == nullptr || current->getData() != 10) {
        cout << "FAILED: First item is incorrect" << endl;
        return;
    }
    
    current = current->getNext();
    if (current == nullptr || current->getData() != 20) {
        cout << "FAILED: Second item is incorrect" << endl;
        return;
    }
    
    current = current->getNext();
    if (current == nullptr || current->getData() != 30) {
        cout << "FAILED: Third item is incorrect" << endl;
        return;
    }
    
    cout << "PASSED" << endl;
}

void testLinkedListRemove() {
    cout << "Testing LinkedList::remove... ";
    
    LinkedList<MenuItem*> menu;
    menu.addBack(new Beverage("Coffee", 3.50, true, "Medium", 80));
    menu.addBack(new Food("Croissant", 2.75, true, nullptr, 0, 200));
    
    bool removed = menu.remove("Coffee");
    
    if (!removed) {
        cout << "FAILED: Could not remove existing item" << endl;
        return;
    }
    
    MenuItem* item = menu.search("Coffee");
    if (item != nullptr) {
        cout << "FAILED: Item was not properly removed" << endl;
        return;
    }
    
    cout << "PASSED" << endl;
    
    menu.clear();
}

void testLinkedListSearch() {
    cout << "Testing LinkedList::search... ";
    
    LinkedList<MenuItem*> menu;
    menu.addBack(new Beverage("Latte", 4.25, true, "Large", 75));
    menu.addBack(new Food("Muffin", 3.00, true, nullptr, 0, 300));
    
    MenuItem* item = menu.search("Latte");
    
    if (item == nullptr || item->getName() != "Latte") {
        cout << "FAILED: Could not find existing item" << endl;
        return;
    }
    
    item = menu.search("Cappuccino");
    
    if (item != nullptr) {
        cout << "FAILED: Found an item that doesn't exist" << endl;
        return;
    }
    
    cout << "PASSED" << endl;
    
    menu.clear();
}