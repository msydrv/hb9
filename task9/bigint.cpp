#include "bigint.h"
#include <string>
#include <vector>
#include <iostream>

BigInt::BigInt(std::string inp) {
    for(const auto& c : inp) {
        this->num.push_back(c-'0');
    }
}

BigInt::BigInt() : num{} {
    
}

BigInt operator+(const BigInt &lhs, const BigInt &rhs) {
    BigInt smaller; 
    BigInt bigger;
    if(lhs.num.size() < rhs.num.size()) {
        smaller = lhs;
        bigger = rhs;
    
    }   else {
        smaller = rhs;
        bigger = lhs;
    } 
    while(smaller.num.size() != bigger.num.size()) {
        smaller.num.insert(smaller.num.begin(), 0);
    }
    BigInt res;
    int a,b, carry_in = 0, carry_out = 0;
    for(int i = bigger.num.size()-1; i>= 0; i--){
        a = smaller.num[i];
        b = bigger.num[i];
        if(a + b + carry_in > 9) {
            res.num.push_back((a+b+carry_in)% 10);
            carry_in = (a+b+carry_in)/10;
            if(i==0) res.num.push_back(carry_in);

        }   else  {
            res.num.push_back(a+b+carry_in);
            carry_in = 0;
        }
    }
    BigInt finalRes;
    for(int i = res.num.size()-1; i >= 0; i--) {
        finalRes.num.push_back(res.num[i]);
    }
    return finalRes; 
}


BigInt operator-(const BigInt &lhs, const BigInt &rhs);
BigInt operator*(const BigInt &lhs, const BigInt &rhs);
BigInt operator/(const BigInt &lhs, const BigInt &rhs);
BigInt operator%(const BigInt &lhs, const BigInt &rhs);


std::ostream& operator<<(std::ostream& o, BigInt x) {
    for(auto & c : x.num) {
        o << c;
    }
    return o;
}