#include <iostream>
#include "LinkedList.h"
#include "MenuItem.h"
#include "Food.h"
#include "Beverage.h"
#include <iomanip>
#include "Menu.h"
#include <string>

using namespace std;

// ========== Menus ==========

void menu_received() {
    cout << "\n          Here is our menu: " << endl;
    cout << "          1. Beverages" << endl;
    cout << "          2. Food" << endl;
    cout << "          3. Checkout & Exit" << endl;
}

void beverages_option() {
    cout << "\n          Please select a category: " << endl;
    cout << "          1. Hot Beverages" << endl;
    cout << "          2. Cold Beverages" << endl;
    cout << "          3. Non-Caffeinated" << endl;
    cout << "          4. Back to Main Menu" << endl;
}

void food_option() {
    cout << "\n          Please select a category: " << endl;
    cout << "          1. Pastries" << endl;
    cout << "          2. Sandwiches" << endl;
    cout << "          3. Snacks" << endl;
    cout << "          4. Back to Main Menu" << endl;
}

void displayItemChoices(LinkedList<std::string>& items) {
    LinkedList<std::string>::Iterator it = items.begin();
    int index = 1;
    while (it.hasNext()) {
        cout << "          " << index << ". " << it.next() << endl;
        index++;
    }
    cout << "          " << index << ". Back\n";
}

// ========== Main ==========

int main() {
    Menu cafeMenu;
    cafeMenu.loadFromFile("menu.txt");
    
    LinkedList<MenuItem*>& masterMenu = cafeMenu.getItems();
    LinkedList<MenuItem*> userOrder;

    LinkedList<std::string> hotDrinks;
    hotDrinks.addBack("Coffee");
    hotDrinks.addBack("Espresso");
    hotDrinks.addBack("Latte");
    hotDrinks.addBack("Caramel Macchiato");

    LinkedList<std::string> coldDrinks;
    coldDrinks.addBack("Iced Coffee");
    coldDrinks.addBack("Iced Latte");

    LinkedList<std::string> nonCaff;
    nonCaff.addBack("Tea");
    nonCaff.addBack("Berry Smoothie");

    LinkedList<std::string> pastries;
    pastries.addBack("Croissant");
    pastries.addBack("Blueberry Scone");
    pastries.addBack("Muffin");

    LinkedList<std::string> sandwiches;
    sandwiches.addBack("Turkey Sandwich");
    sandwiches.addBack("Ham Sandwich");
    sandwiches.addBack("Veggie Sandwich");

    LinkedList<std::string> snacks;
    snacks.addBack("Chips");
    snacks.addBack("Pretzels");

    int userChoice, subChoice;
    bool backToMain = false;

    cout << "----- Welcome to The Cozy Bean -----" << endl;

    do {
        menu_received();
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1: { // Beverages
                do {
                    beverages_option();
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
                        
                        // Check if the user selected "Back" option
                        if (subChoice == maxChoice + 1) {
                            // User chose "Back", continue to the category selection
                            continue;
                        }
                        
                        if (subChoice >= 1 && subChoice <= maxChoice) {
                            std::string itemName = currentList->get(subChoice - 1);
                            MenuItem* item = masterMenu.search(itemName);
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
                break;
            }

            case 2: { // Food
                do {
                    food_option();
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
                            MenuItem* item = masterMenu.search(itemName);
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
                break;
            }
                
            case 3: { // Checkout & Exit
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
                    cout << "Your total is: $" << fixed << setprecision(2) << total << endl;

                }
                
                cafeMenu.saveToFile("menu_updated.txt");
                
                cout << "Thank you for visiting The Cozy Bean!\n";
                break;
            }

            default:
                cout << "Invalid choice.\n";
        }

    } while (userChoice != 3);

    return 0;
}