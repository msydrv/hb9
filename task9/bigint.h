#include<vector>
#include<string>

class BigInt {
    std::vector<unsigned> num;
public:
    BigInt(std::string);
    BigInt();
    
    friend BigInt operator+(const BigInt &lhs, const BigInt &rhs);
    friend BigInt operator-(const BigInt &lhs, const BigInt &rhs);
    friend BigInt operator*(const BigInt &lhs, const BigInt &rhs);
    friend BigInt operator/(const BigInt &lhs, const BigInt &rhs);
    friend BigInt operator%(const BigInt &lhs, const BigInt &rhs);
    friend std::ostream& operator<<(std::ostream& o, BigInt x);
};
std::ostream& operator<<(std::ostream& o, BigInt x);
BigInt operator+(const BigInt &lhs, const BigInt &rhs);
BigInt operator-(const BigInt &lhs, const BigInt &rhs);
BigInt operator*(const BigInt &lhs, const BigInt &rhs);
BigInt operator/(const BigInt &lhs, const BigInt &rhs);
BigInt operator%(const BigInt &lhs, const BigInt &rhs);