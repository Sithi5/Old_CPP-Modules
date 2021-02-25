#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy){
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;

    return;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs){
        this->setRawBits(rhs.getRawBits());
    }
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(const int value) {
    this->_fixedPointValue = value;
}


