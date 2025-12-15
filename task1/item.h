#ifndef ITEM_H
#define ITEM_H

#include<string>
#include<stdexcept>
#include<iostream>

#include "ean_code.h"

enum struct Category {Clothing, Electronics, Game, Food};

std::string categoryToString(Category c);


class Item {
    
    EAN_code code;
    std::string name;
    std::string description;
    double price;
    Category caregory;
public:
    Item(EAN_code code, std::string name, std::string description, double price, Category caregory);

    std::ostream& print(std::ostream &o);


    void setCode(const std::string &code);

    void setName(const std::string &name);

    void setDescription(const std::string &description);

    void setPrice(const double &price);

    void setCategory(const Category& c);

    friend class Shop;

    bool in_category(Category c) const; 

};

std::ostream& operator<<(std::ostream& o, Item& x);

#endif