#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include<iostream>

class Vector {
    std::vector<double> v;
public:
    Vector(const std::vector<double>&);

    Vector(unsigned n);

    Vector operator+(const Vector& rhs) const;
    Vector operator-(const Vector& rhs) const;
    Vector operator*(double scalar) const;
    Vector operator/(const Vector& rhs) const;

    double norm() const;
    void print();

    friend std::ostream& operator<<(std::ostream&, const Vector&);
};

std::ostream& operator<<(std::ostream&, const Vector&);

#endif