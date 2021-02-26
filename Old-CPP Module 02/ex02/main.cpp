#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "max between a and b : " << max(a, b) << std::endl;
    std::cout << "min between a and b : " << min(a, b) << std::endl;
    return 0;
}