#include "CafeApp.h"
#include <iostream>
#include <iomanip>

using namespace std;

CafeApp::CafeApp() {
    cafeMenu.loadFromFile("menu.txt");
    
    initializeCategoryLists();
}

void CafeApp::initializeCategoryLists() {
    hotDrinks.addBack("Coffee");
    hotDrinks.addBack("Espresso");
    hotDrinks.addBack("Latte");
    hotDrinks.addBack("Caramel Macchiato");
    
    coldDrinks.addBack("Iced Coffee");
    coldDrinks.addBack("Iced Latte");
    
    nonCaff.addBack("Tea");
    nonCaff.addBack("Berry Smoothie");
    
                                                                               pastries.addBack("Croissant");
    pastries.addBack("Blueberry Scone");
    pastries.addBack("Muffin");
    
    sandwiches.addBack("Turkey Sandwich");
    sandwiches.addBack("Ham Sandwich");
    sandwiches.addBack("Veggie Sandwich");
    
    snacks.addBack("Chips");
    snacks.addBack("Pretzels");
}

void CafeApp::displayMainMenu() {
    cout << "\n          Here is our menu: " << endl;
    cout << "          1. Beverages" << endl;
    cout << "          2. Food" << endl;
    cout << "          3. Checkout & Exit" << endl;
}

void CafeApp::displayBeverageOptions() {
    cout << "\n          Please select a category: " << endl;
    cout << "          1. Hot Beverages" << endl;
    cout << "          2. Cold Beverages" << endl;
    cout << "          3. Non-Caffeinated" << endl;
    cout << "          4. Back to Main Menu" << endl;
}

void CafeApp::displayFoodOptions() {
    cout << "\n          Please select a category: " << endl;
    cout << "          1. Pastries" << endl;
    cout << "          2. Sandwiches" << endl;
    cout << "          3. Snacks" << endl;
    cout << "          4. Back to Main Menu" << endl;
}

void CafeApp::displayItemChoices(LinkedList<std::string>& items) {
    LinkedList<std::string>::Iterator it = items.begin();
    int index = 1;
    while (it.hasNext()) {
        cout << "          " << index << ". " << it.next() << endl;
        index++;
    }
    cout << "          " << index << ". Back\n";
}

void CafeApp::handleBeverages() {
    int subChoice;
    do {
        displayBeverageOptions();
        cout << "Enter your choice: ";
        cin >> subChoice;
        
        LinkedList<std::string>* currentList = nullptr;
        int maxChoice = 0;
        
        if (subChoice == 1) {
            currentList = &hotDrinks;
            maxChoice = 4;
        } else if (subChoice == 2) {
            currentList = &coldDrinks;
            maxChoice = 2;
        } else if (subChoice == 3) {
            currentList = &nonCaff;
            maxChoice = 2;
        } else if (subChoice == 4) {
            break;
        } else {
            cout << "Invalid choice.\n";
            continue;
        }
        
        if (currentList != nullptr) {
            displayItemChoices(*currentList);
            cout << "Enter your choice: ";
            cin >> subChoice;
            
            if (subChoice == maxChoice + 1) {
                continue;
            }
            
            if (subChoice >= 1 && subChoice <= maxChoice) {
                std::string itemName = currentList->get(subChoice - 1);
                MenuItem* item = cafeMenu.getItems().search(itemName);
                if (item != nullptr) {
                    userOrder.addBack(item);
                    cout << "Added: " << item->getName() << "\n";
                } else {
                    cout << "Item not found in menu.\n";
                }
            } else {
                cout << "Invalid choice.\n";
            }
        }
    } while (subChoice != 4);
}

void CafeApp::handleFood() {
    int subChoice;
    do {
        displayFoodOptions();
        cout << "Enter your choice: ";
        cin >> subChoice;
        
        LinkedList<std::string>* currentList = nullptr;
        int maxChoice = 0;
        
        if (subChoice == 1) {
            currentList = &pastries;
            maxChoice = 3;
        } else if (subChoice == 2) {
            currentList = &sandwiches;
            maxChoice = 3;
        } else if (subChoice == 3) {
            currentList = &snacks;
            maxChoice = 2;
        } else if (subChoice == 4) {
            // Back to main menu
            break;
        } else {
            cout << "Invalid choice.\n";
            continue;
        }
        
        if (currentList != nullptr) {
            displayItemChoices(*currentList);
            cout << "Enter your choice: ";
            cin >> subChoice;
            
            if (subChoice == maxChoice + 1) {
                continue;
            }
            
            if (subChoice >= 1 && subChoice <= maxChoice) {
                std::string itemName = currentList->get(subChoice - 1);
                MenuItem* item = cafeMenu.getItems().search(itemName);
                if (item != nullptr) {
                    userOrder.addBack(item);
                    cout << "Added: " << item->getName() << "\n";
                } else {
                    cout << "Item not found in menu.\n";
                }
            } else {
                cout << "Invalid choice.\n";
            }
        }
    } while (subChoice != 4);
}

void CafeApp::checkout() {
    cout << "\n----- Your Order Summary -----\n";
    
    if (userOrder.getHead() == nullptr) {
        cout << "Your order is empty.\n";
    } else {
        double total = 0.0;
        Node<MenuItem*>* current = userOrder.getHead();
        while (current != nullptr) {
            MenuItem* item = current->getData();
            cout << item->getName() << " - $" << fixed << setprecision(2) << item->getPrice() << endl;
            total += item->getPrice();
            current = current->getNext();
        }
        cout << "Total: $" << fixed << setprecision(2) << total << endl;
    }
    
    // Save menu back to file
    cafeMenu.saveToFile("menu_updated.txt");
    
    cout << "Thank you for visiting The Cozy Bean!\n";
}

void CafeApp::run() {
    int userChoice;
    
    cout << "----- Welcome to The Cozy Bean -----" << endl;
    
    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> userChoice;
        
        switch (userChoice) {
            case 1:
                handleBeverages();
                break;
            case 2:
                handleFood();
                break;
            case 3:
                checkout();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (userChoice != 3);
}