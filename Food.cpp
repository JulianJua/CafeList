#include "Food.h"

Food::Food(std::string name, double price, bool available,
           std::string ingredientsInput[], int count, int calories)
    : MenuItem("", 0.0, false)
{
    this->name = name;
    this->price = price;
    this->available = available;

    this->calories = calories;
    this->ingredientCount = count;

    for (int i = 0; i < count && i < 5; ++i) {
        this->ingredients[i] = ingredientsInput[i];
    }

    for (int i = count; i < 5; ++i) {
        this->ingredients[i] = "";
    }
}

std::string Food::getCategory() const {
    return "Food";
}

void Food::getAllergens(std::string output[], int& count) const {
    count = this->ingredientCount;
    for (int i = 0; i < count; ++i) {
        output[i] = this->ingredients[i];
    }
}
