#include<string>
#include<stdexcept>
#include<iostream>
#include<vector>

#include"shop.h"

Shop::Shop(std::string URL,
           std::string name,
           std::string road,
           std::string street_number,
           std::string zip_code,
           std::string city,
           std::vector<Item> items) : 
                                        URL(URL),
                                        name(name),
                                        road(road),
                                        street_number(street_number),
                                        zip_code(zip_code),
                                        city(city),
                                        items(items) {
    if(this->name.empty()) throw std::runtime_error("Shop::empty name");
    if(this->road.empty()) throw std::runtime_error("Shop::empty road");
    if(this->street_number.empty()) throw std::runtime_error("Shop::empty street_number");
    if(this->zip_code.empty()) throw std::runtime_error("Shop::empty zip_code");
    if(this->city.empty()) throw std::runtime_error("Shop::empty city");
}



std::ostream& operator<<(std::ostream& o, Shop& x) {
    o << x.URL << "\n" 
        << x.name << "\n" 
        << x.road << " " 
        << x.street_number << "\n" 
        << x.zip_code << " " 
        << x.city << "\n"
        << "-------------\n";
    for(Item& i : x.items) {
        o << i << "\n";
        o << "-------------";
    }
    return o;
}



Item& Shop::findItem(const EAN_code& x) {
    for(Item &i : this->items) {
        if(i.code.getEan() == x.getEan()) return i;
    }
    throw std::runtime_error("Shop::findItem::Not Found");
}



void Shop::add_item(const Item& x) {
    for(Item &i : this->items) {
        if(i.code.getEan() == x.code.getEan()) throw std::runtime_error("Shop::addItem:: Alredy in Sortiment");
    }
    this->items.push_back(x);
}


bool Shop::del_item(const EAN_code& x) {
    std::vector<Item> newItems;
    for(const Item &i : this->items) {
        if(i.code.getEan() != x.getEan()) newItems.push_back(i);
    }
    swap(this->items, newItems);
    return this->items.size() != newItems.size();
}