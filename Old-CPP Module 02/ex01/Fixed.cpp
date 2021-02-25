//
// Created by MaSit on 25/02/2021.
//

#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "int constructor called" << std::endl;
    this->setRawBits(value * (1 << this->_fractBits));
}

Fixed::Fixed(const float value) {
    std::cout << "float constructor called" << std::endl;
    this->setRawBits(roundf((value * (float)(1 << this->_fractBits))));
}

Fixed::Fixed(Fixed const &copy){
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;

    return;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
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
    this->_fixedPointValue = value << 8;}

float Fixed::toFloat(void) const {
    return (this->_fixedPointValue / (float)(1 << this->_fractBits));
}

int Fixed::toInt(void) const {
    return (this->_fixedPointValue / (1 << this->_fractBits));
}


std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.getRawBits();
    return os;
}

