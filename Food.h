#ifndef FOOD_H
#define FOOD_H

#include "MenuItem.h"

class Food : public MenuItem {
private:
    std::string ingredients[5];
    int ingredientCount;
    int calories;

public:
    Food(std::string name, double price, bool available,
         std::string ingredientsInput[], int count, int calories);

    std::string getCategory() const override;
    void getAllergens(std::string output[], int& count) const;
};

#endif
