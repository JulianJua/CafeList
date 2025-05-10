#include <iostream>
#include "LinkedList.h"
#include "MenuItem.h"
#include "Food.h"
#include "Beverage.h"

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

// ========== Add Menu Items ==========

void addMenuItems(LinkedList<MenuItem*>& masterMenu) {
    masterMenu.addBack(new Beverage("Coffee", 3.50, true, "Small", 80));
    masterMenu.addBack(new Beverage("Espresso", 3.00, true, "Small", 85));
    masterMenu.addBack(new Beverage("Latte", 4.50, true, "Medium", 75));
    masterMenu.addBack(new Beverage("Caramel Macchiato", 5.00, true, "Large", 78));
    masterMenu.addBack(new Beverage("Iced Coffee", 3.75, true, "Large", 40));
    masterMenu.addBack(new Beverage("Iced Latte", 4.25, true, "Large", 42));
    masterMenu.addBack(new Beverage("Tea", 2.50, true, "Medium", 65));
    masterMenu.addBack(new Beverage("Berry Smoothie", 4.95, true, "Medium", 5));

    masterMenu.addBack(new Food("Croissant", 3.25, true, nullptr, 0, 300));
    masterMenu.addBack(new Food("Blueberry Scone", 3.75, true, nullptr, 0, 320));
    masterMenu.addBack(new Food("Muffin", 2.95, true, nullptr, 0, 310));
    masterMenu.addBack(new Food("Turkey Sandwich", 6.99, true, nullptr, 0, 550));
    masterMenu.addBack(new Food("Ham Sandwich", 6.50, true, nullptr, 0, 540));
    masterMenu.addBack(new Food("Veggie Sandwich", 5.99, true, nullptr, 0, 500));
    masterMenu.addBack(new Food("Chips", 1.50, true, nullptr, 0, 200));
    masterMenu.addBack(new Food("Pretzels", 1.75, true, nullptr, 0, 210));
}

// ========== Main ==========

int main() {
    LinkedList<MenuItem*> masterMenu;
    LinkedList<MenuItem*> userOrder;

    addMenuItems(masterMenu);

    // LinkedLists for categories
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
                    } else {
                        break;
                    }

                    if (currentList != nullptr) {
                        displayItemChoices(*currentList);
                        cin >> subChoice;
                        if (subChoice >= 1 && subChoice <= maxChoice) {
                            std::string itemName = currentList->get(subChoice - 1);
                            MenuItem* item = masterMenu.search(itemName);
                            if (item != nullptr) {
                                userOrder.addBack(item);
                                cout << "Added: " << item->getName() << "\n";
                            }
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
                    } else {
                        break;
                    }

                    if (currentList != nullptr) {
                        displayItemChoices(*currentList);
                        cin >> subChoice;
                        if (subChoice >= 1 && subChoice <= maxChoice) {
                            std::string itemName = currentList->get(subChoice - 1);
                            MenuItem* item = masterMenu.search(itemName);
                            if (item != nullptr) {
                                userOrder.addBack(item);
                                cout << "Added: " << item->getName() << "\n";
                            }
                        }
                    }
                } while (subChoice != 4);
                break;
            } // Added closing brace here
                
            case 3: { // Checkout & Exit
                cout << "\n----- Your Order Summary -----\n";
                
                if (userOrder.getHead() == nullptr) {
                    cout << "Your order is empty.\n";
                } else {
                    double total = 0.0;
                    Node<MenuItem*>* current = userOrder.getHead();
                    while (current != nullptr) {
                        MenuItem* item = current->getData();
                        cout << item->getName() << " - $" << item->getPrice() << endl;
                        total += item->getPrice();
                        current = current->getNext();
                    }
                    cout << "Total: $" << total << endl;
                }
                
                cout << "Thank you for visiting The Cozy Bean!\n";
                break;
            }

            default:
                cout << "Invalid choice.\n";
        }

    } while (userChoice != 3);

    return 0;
}