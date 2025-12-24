#include"struct.h"


#include<iostream>

int main() {    
    std::cout << Stack(0, 0);
    std::cout << Stack(0, 1);
    std::cout << Stack(0, 5);
    std::cout << Stack(1, 0);
    std::cout << Stack(2, 0);
    std::cout << Stack(3, 0);
    std::cout << Stack(1, 2);
    std::cout << Stack(1, 5);
    std::cout << Stack(3, 6);
    std::cout << Stack(3, 7);
    return 0;
}