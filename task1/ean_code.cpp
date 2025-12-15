#include<stdexcept>
#include<iostream>
#include<string>


#include"ean_code.h"

EAN_code::EAN_code(std::string ean_code) : ean_code(ean_code){
    if(ean_code.size() != 13) throw std::runtime_error("EAN_code::Wring size");
    for(const char &c : ean_code) {
        if(c < '0' || c > '9') throw std::runtime_error("EAN_code:Wrong symbol");
    }
}

std::ostream& EAN_code::print(std::ostream& o){
    o << this->ean_code;
    return o;
}


bool operator<(const EAN_code &rhs, const EAN_code &lhs) {
    return rhs.ean_code<lhs.ean_code;
}

bool operator>=(const EAN_code &rhs, const EAN_code &lhs) {
    return !(rhs<lhs);
}

bool operator>(const EAN_code &rhs, const EAN_code &lhs) {
    return lhs<rhs;
}


bool operator==(const EAN_code &rhs, const EAN_code &lhs) {
    return !(rhs<lhs) && !(lhs<rhs);
}
bool operator!=(const EAN_code &rhs, const EAN_code &lhs) {
    return !(!(rhs<lhs) && !(lhs<rhs));
}

bool operator<=(const EAN_code &rhs, const EAN_code &lhs) {
    return !(rhs<lhs);
}

std::ostream& operator<<(std::ostream& o, EAN_code& code) {
    return code.print(o);
}
