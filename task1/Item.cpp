#include<string>
#include<stdexcept>
#include<iostream>

#include "item.h"

std::ostream& Item::print(std::ostream& o) {
    o << this->code << ": "<< this->name << " " << this->price/100 << "\n";
    o << categoryToString(this->caregory) << "\n";
    o << this->description << " " << this->price;
    return o;
}


Item::Item(EAN_code code, std::string name, std::string description, double price, Category caregory) 
            : code(code), name(name), description(description), price(price), caregory(caregory){
    if(this->name.empty()) throw std::runtime_error("Item::Empty Name");
    if(this->price <= 0 ) throw std::runtime_error("Item::Invalid price");
}


void Item::setCode(const std::string &code) {
    if(code.size() != 13) throw std::runtime_error("Set Item:: Invalid ean code size");
    for(const char &c : code) {
        if(c < '1' || c > '9') throw std::runtime_error("Set Item:: wrong symbol");
    }
    this->code.ean_code = code;
}

void Item::setName(const std::string &name) {
    if(name.empty()) throw std::runtime_error("setName:: Empty name");
    this->name = name;
}

void Item::setDescription(const std::string &description) {
    this->description = description;
}

void Item::setPrice(const double &price) {
    if(price<=0) throw std::runtime_error("setPrice:: Invalid price");
    this->price = price;
}

void Item::setCategory(const Category& c) {
    this->caregory = c;
}

bool Item::in_category(Category c) const {return this->caregory == c;}

std::ostream& operator<<(std::ostream& o, Item& x) {
    return x.print(o);
}


std::string categoryToString(Category c){
    switch(c) {
        case Category::Clothing: return "Clothing";
        case Category::Electronics: return "Electronics";
        case Category::Game: return "Game";
        case Category::Food: return "Food";
        default: return "Other";
    }
}