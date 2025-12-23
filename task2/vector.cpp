#include <vector>
#include "vector.h"
#include <iostream>

Vector::Vector(const std::vector<double>& v) : v(v) {}

Vector::Vector(unsigned n) {
    while(n--) {
        v.push_back(0.0);
    }
    v = v;
}
Vector Vector::operator+(const Vector& rhs) const {
    std::vector<double> res;
    for(unsigned i = 0; i < this->v.size(); i++) {
        res.push_back(this->v[i] + rhs.v[i]);
    }   
    return res;
}



Vector Vector::operator-(const Vector& rhs) const {
    std::vector<double> res;
    for(unsigned i = 0; i < this->v.size(); i++)
    {
        res.push_back(this->v[i] - rhs.v[i]);
    }
    return res;
}

Vector Vector::operator*(double scalar) const {
    std::vector<double> res;
    for(unsigned i = 0; i < this->v.size(); i++) {
        res.push_back(this->v[i] * scalar);
    }
    return res;
}

Vector Vector::operator/(const Vector& rhs) const {
    if(rhs.v.size() != 3) throw std::runtime_error("Size should be 3");
    std::vector<double> res;
    res.push_back(this->v[2] * rhs.v[3] - this->v[3] * rhs.v[2]);
    res.push_back(this->v[3] * rhs.v[1] - this->v[1] * rhs.v[3]);
    res.push_back(this->v[1] * rhs.v[2] - this->v[2] * rhs.v[1]);
    return res;
}

double Vector::norm() const {
    double res = 0;
    unsigned s = this->v.size();
    while(s--) {
        res = res + this->v[s];
    }
    res = sqrt(res);
    return res;
}


void Vector::print() {
    std::cout << this;
}

std::ostream& operator<<(std::ostream& o, const Vector& x) {
    o << "[ ";
    for(const auto &c : x.v) {
        o << "{" << c << "} ";
    }
    return o << " ]";
}