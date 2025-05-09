#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
protected:
    std::string name;
    double price;
    bool available;

public:
    MenuItem(std::string name, double price, bool available);
    virtual ~MenuItem() = default;

    std::string getName() const;
    double getPrice() const;
    bool isAvailable() const;

    virtual std::string getCategory() const = 0;
};

#endif
