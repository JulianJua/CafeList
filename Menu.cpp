#include "Menu.h"
#include <iostream>
#include <fstream>  
#include <string>
#include "Beverage.h"
#include "Food.h"


void Menu::loadFromFile(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return;
    }
    
    std::string line;
    items.clear();
    
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        std::string type, name, available, size;
        double price;
        int temp, calories;
        
        size_t pos = line.find(",");
        type = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find(",");
        name = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find(",");
        price = std::stod(line.substr(0, pos));
        line.erase(0, pos + 1);
        
        pos = line.find(",");
        available = line.substr(0, pos);
        bool isAvailable = (available == "1" || available == "true");
        line.erase(0, pos + 1);
        
        if (type == "Beverage") {
            pos = line.find(",");
            size = line.substr(0, pos);
            line.erase(0, pos + 1);
            
            temp = std::stoi(line);
            
            items.addBack(new Beverage(name, price, isAvailable, size, temp));
        } 
        else if (type == "Food") {
            pos = line.find(",");
            calories = std::stoi(line.substr(0, pos));
            
            items.addBack(new Food(name, price, isAvailable, nullptr, 0, calories));
        }
    }
    
    file.close();
    std::cout << "Menu loaded from file: " << filename << std::endl;
}

void Menu::saveToFile(std::string filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return;
    }
    
    Node<MenuItem*>* current = items.getHead();
    while (current != nullptr) {
        MenuItem* item = current->getData();
        
        file << item->getCategory() << "," 
             << item->getName() << "," 
             << item->getPrice() << ","
             << (item->isAvailable() ? "1" : "0");
        
        if (item->getCategory() == "Beverage") {
            Beverage* bev = dynamic_cast<Beverage*>(item);
            file << "," << "Medium" << "," << bev->getTemp();  
        } 
        else if (item->getCategory() == "Food") {
            Food* food = dynamic_cast<Food*>(item);
            file << "," << "300" << ",0";
        }
        
        file << std::endl;
        current = current->getNext();
    }
    
    file.close();
    std::cout << "Menu saved to file: " << filename << std::endl;
}