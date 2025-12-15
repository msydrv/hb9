#ifndef SHOP_H
#define SHOP_H

#include<string>
#include<stdexcept>
#include<iostream>
#include<vector>

#include"item.h"

class Shop{
    std::string URL;
    std::string name;
    std::string road;
    std::string street_number;
    std::string zip_code;
    std::string city;
    std::vector<Item> items;
public:
    Shop(std::string URL,
         std::string name,
         std::string road,
         std::string street_number,
         std::string zip_code,
         std::string city,
         std::vector<Item> items);

    friend std::ostream& operator<<(std::ostream& o, Shop& x);

    Item& findItem(const EAN_code& x);

    void add_item(const Item& x);

    bool del_item(const EAN_code& x);
};

std::ostream& operator<<(std::ostream& o, Shop& x);

#endif