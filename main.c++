#include <iostream>
using namespace std;

void menu_received() {
    // menu to user
    cout << endl;
    cout << "          Here is our menu: " << endl;
    cout << "          1. Beverages" << endl;
    cout << "          2. Food" << endl;
    cout << "          3. Exit" << endl;
    cout << endl;

}
void beverages_option(){
    cout << endl;
    cout << "          Please select a category: " << endl;
    cout << "          1. Hot Beverages" << endl;
    cout << "          2. Cold Beverages" << endl;
    cout << "          3. Non-Caffeinated" << endl;
    cout << "          4. Back to Main Menu" << endl;
    cout << endl;
}

void food_option(){
    cout << endl;
    cout << "          Please select a category: " << endl;
    cout << "          1. Pastries" << endl;
    cout << "          2. Sandwiches" << endl;
    cout << "          3. Snacks" << endl;
    cout << "          4. Back to Main Menu" << endl;
    cout << endl;
}

void hot_beverages_menu() {
    cout << endl;
    cout << "---------- Hot Beverages -----------" << endl;
    cout << endl;
    cout << "          1. Coffee" << endl;
    cout << "          2. Espresso" << endl;
    cout << "          3. Latte" << endl;
    cout << "          4. Caramel Macchiato" << endl;
    // ... more options
    cout << "          5. Back to Beverages Menu" << endl;

}

void cold_beverages_menu() {
    cout << endl;
    cout << "---------- Cold Beverages ----------" << endl;
    cout << endl;
    cout << "          1. Iced Coffee" << endl;
    cout << "          2. Iced Latte" << endl;
    cout << "          3. Iced Caramel Macchiato" << endl;
    // ... more options
    cout << "          5. Back to Beverages Menu" << endl;

}

void non_caffeinated_menu() {
    cout << endl;
    cout << "---------- Non-Caffeinated ----------" << endl;
    cout << endl;
    cout << "          1. Tea" << endl;
    cout << "          2. Lemon Tea" << endl;
    cout << "          3. Berry Smoothie" << endl;
    // ... more options
    cout << "          5. Back to Beverages Menu" << endl;

}

void pastries_menu() {
    cout << endl;
    cout << "------------- Pastries -------------" << endl;
    cout << endl;
    cout << "          1. Croissant" << endl;
    cout << "          2. Blueberry Scone" << endl;
    cout << "          3. Muffin" << endl;
    cout << "          4. Matcha White Chocolate Macadamia Nut Cookie " << endl;
    // ... more options
    cout << "          5. Back to Food Menu" << endl;

}

void sandwiches_menu(){
    cout << endl;
    cout << "------------- Sandwiches ------------" << endl;
    cout << endl;
    cout << "          1. Turkey" << endl;
    cout << "          2. Ham" << endl;
    cout << "          3. Salami" << endl;
    cout << "          4. Veggie" << endl;
    // ... more options
    cout << "          5. Back to Food Menu" << endl;
    cout << endl;
}

void snack_menu(){
    cout << endl;
    cout << "------------- Snacks ----------------" << endl;
    cout << endl;
    cout << "          1. Chips" << endl;
    cout << "          2. Crackers" << endl;
    cout << "          3. Pretzels" << endl;
    cout << "          4. Chex-mix" << endl;
    // ... more options
    cout << "          5. Back to Food Menu" << endl;
    cout << endl;
}

void end() {
cout << endl;
cout << "------------------------------------" << endl;
cout << "      Thank you and come again!" << endl;
cout << "------------------------------------" << endl;
}

int main() {
    int userChoice;
    int beverageChoice;
    int foodChoice;
    int foodSubChoice; // To handle choices within Pastries, Sandwiches, Snacks

    cout << "----- Welcome to The Cozy Bean -----" << endl;
    menu_received();

    do {
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1: // Beverages
                beverages_option();
                cout << "Enter your choice: ";
                cin >> beverageChoice;
                switch (beverageChoice) {
                    case 1:
                        hot_beverages_menu();
                        cout << "Enter your choice: ";
                        cin >> beverageChoice; // Get choice from hot beverages
                        if (beverageChoice == 5) beverages_option();
                        break;
                    case 2:
                        cold_beverages_menu();
                        cout << endl;
                        cout << "Enter your choice: ";
                        cin >> beverageChoice; // Get choice from cold beverages
                        if (beverageChoice == 5) beverages_option();
                        break;
                    case 3:
                        non_caffeinated_menu();
                        cout << "Enter your choice: ";
                        cin >> beverageChoice; // Get choice from non-caffeinated
                        if (beverageChoice == 5) beverages_option();
                        break;
                    case 4:
                        break; // Back to Main Menu - will exit the inner switch
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            case 2: // Food
                food_option();
                cout << "Enter your choice: ";
                cin >> foodChoice;
                while (foodChoice != 4) { // Stay in Food menu until 'Back to Main Menu'
                    switch (foodChoice) {
                        case 1:
                            pastries_menu();
                            cout << "Enter your choice: ";
                            cin >> foodSubChoice;
                            if (foodSubChoice == 5) food_option();
                            break;
                        case 2:
                            sandwiches_menu();
                            cout << "Enter your choice: ";
                            cin >> foodSubChoice;
                            if (foodSubChoice == 5) food_option();
                            break;
                        case 3:
                            snack_menu();
                            cout << "Enter your choice: ";
                            cin >> foodSubChoice;
                            if (foodSubChoice == 5) food_option(); 
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                    if (foodChoice != 4) {
                        cout << "Enter your choice: ";
                        cin >> foodChoice;
                    }
                }
                break;
            case 3: // Exit
                end();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (userChoice != 3);

    return 0;
}