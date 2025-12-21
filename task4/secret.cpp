#include<string>
#include<stdexcept>
#include<iostream>

#include "secret.h"

Secret::Secret(const std::string& information) : info{information}, pass{} {

} 


Secret::Secret(const std::string& information, const std::string& pass) : info{information}, pass{pass} {

}

bool Secret::lock(const std::string &pass) {
    if(this->pass.empty()) {
        this->pass = pass;
        return true;
    }
    return false;
}


bool Secret::unlock(const std::string &pass) {
    if(pass == this->pass) {
        this->pass = "";
        return true;
    }
    return false;
}

int Secret::len() const{
    if(this->pass.empty()) {
        return this->info.size();
    }
    return 0;
}


Secret Secret::operator+(const Secret &rhs) {
    if((rhs.pass.empty()) && (this->pass.empty())) {
        std::string res = rhs.info + this->info;
        return res;
    }
    throw std::runtime_error("Secret::operator+::locked");
}

std::ostream& operator<<(std::ostream& o, Secret x) {
    if(x.pass.empty()) return o << x.info;
    return o;
}