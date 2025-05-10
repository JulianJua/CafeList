#include <iostream>
#include <string>
#include "MenuItem.h"
#include "Beverage.h"
#include "Food.h"

using namespace std;

void testBeverageCreation();
void testFoodCreation();
void testMenuItemBasicProperties();

int main() {
    cout << "===== Running MenuItem Tests =====" << endl;
    
    testBeverageCreation();
    testFoodCreation();
    testMenuItemBasicProperties();
    
    cout << "All MenuItem tests completed." << endl;
    return 0;
}

void testBeverageCreation() {
    cout << "Testing Beverage creation... ";
    
    Beverage coffee("Coffee", 3.50, true, "Medium", 80);
    
    if (coffee.getName() != "Coffee") {
        cout << "FAILED: Name not set correctly" << endl;
        return;
    }
    
    if (coffee.getPrice() != 3.50) {
        cout << "FAILED: Price not set correctly" << endl;
        return;
    }
    
    cout << "PASSED" << endl;
}

void testFoodCreation() {
    cout << "Testing Food creation... ";
    
    Food croissant("Croissant", 2.75, true, nullptr, 0, 250);
    
    if (croissant.getName() != "Croissant") {
        cout << "FAILED: Name not set correctly" << endl;
        return;
    }
    
    if (croissant.getPrice() != 2.75) {
        cout << "FAILED: Price not set correctly" << endl;
        return;
    }
    
    cout << "PASSED" << endl;
}

void testMenuItemBasicProperties() {
    cout << "Testing basic MenuItem properties... ";
    
    Beverage coffee("Coffee", 3.50, true, "Medium", 80);
    Food muffin("Blueberry Muffin", 2.95, true, nullptr, 0, 300);
    
    if (coffee.getName() != "Coffee" || muffin.getName() != "Blueberry Muffin") {
        cout << "FAILED: Names not retrieved correctly" << endl;
        return;
    }
    
    if (coffee.getPrice() != 3.50 || muffin.getPrice() != 2.95) {
        cout << "FAILED: Prices not retrieved correctly" << endl;
        return;
    }
    
    if (!coffee.isAvailable() || !muffin.isAvailable()) {
        cout << "FAILED: Availability not set correctly" << endl;
        return;
    }
    
    cout << "PASSED" << endl;
}