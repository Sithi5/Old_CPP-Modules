//
// Created by MaSit on 25/02/2021.
//

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "int constructor called" << std::endl;
    this->setRawBits(value);
}

Fixed::Fixed(const float value) {
    std::cout << "float constructor called" << std::endl;
    this->setRawBits(value);
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;

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
    return this->_value;
}

void Fixed::setRawBits(const int raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return 0;
}

int Fixed::toInt(void) const {
    return 0;
}


std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << "_value: " << fixed.getRawBits();
    return os;
}

