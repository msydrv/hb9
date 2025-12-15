#ifndef EAN_CODE_H
#define EAN_CODE_H

#include<stdexcept>
#include<iostream>
#include<string>

class EAN_code{
    std::string ean_code;
public:
    EAN_code(std::string ean_code);

    std::ostream& print(std::ostream& o);

    friend bool operator<(const EAN_code &rhs, const EAN_code &lhs);

    friend class Item;

    std::string getEan() const { return this->ean_code; }
};
bool operator>=(const EAN_code &rhs, const EAN_code &lhs);  
bool operator>(const EAN_code &rhs, const EAN_code &lhs);
bool operator==(const EAN_code &rhs, const EAN_code &lhs);
bool operator!=(const EAN_code &rhs, const EAN_code &lhs);
bool operator<=(const EAN_code &rhs, const EAN_code &lhs);


std::ostream& operator<<(std::ostream& o, EAN_code& code);



#endif