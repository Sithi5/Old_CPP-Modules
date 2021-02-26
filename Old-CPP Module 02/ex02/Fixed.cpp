#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "int constructor called" << std::endl;
    this->_fixedPointValue = value << this->_fractBits;
}

Fixed::Fixed(const float value) {
    std::cout << "float constructor called" << std::endl;
    this->_fixedPointValue = (int)roundf((value * (float)(1 << this->_fractBits)));
}

Fixed::Fixed(Fixed const &copy){
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;

    return;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}


Fixed   &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs){
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

bool    Fixed::operator==(const Fixed &rhs) const {
    std::cout << "Equality operator called" << std::endl;
    return (this->_fixedPointValue == rhs._fixedPointValue);
}

bool    Fixed::operator!=(const Fixed &rhs) const {
    std::cout << "Not equal operator called" << std::endl;
    return (this->_fixedPointValue != rhs._fixedPointValue);
}

bool    Fixed::operator<=(const Fixed &rhs) const {
    std::cout << "Inferior or equal operator called" << std::endl;
    return (this->_fixedPointValue <= rhs._fixedPointValue);
}

bool    Fixed::operator>=(const Fixed &rhs) const {
    std::cout << "Superior or equal operator called" << std::endl;
    return (this->_fixedPointValue >= rhs._fixedPointValue);
}

bool    Fixed::operator<(const Fixed &rhs) const {
    std::cout << "Inferior operator called" << std::endl;
    return (this->_fixedPointValue < rhs._fixedPointValue);
}

bool    Fixed::operator>(const Fixed &rhs) const {
    std::cout << "Superior operator called" << std::endl;
    return (this->_fixedPointValue > rhs._fixedPointValue);
}

Fixed   Fixed::operator+(const Fixed &rhs) const {
    std::cout << "Addition operator called" << std::endl;
    return(Fixed(this->_fixedPointValue + rhs._fixedPointValue));
}

Fixed   Fixed::operator-(const Fixed &rhs) const {
    std::cout << "Substraction operator called" << std::endl;
    return(Fixed(this->_fixedPointValue - rhs._fixedPointValue));
}

Fixed   Fixed::operator*(const Fixed &rhs) const {
    std::cout << "Multiplication operator called" << std::endl;
    return(Fixed(this->_fixedPointValue * rhs._fixedPointValue));
}

Fixed   Fixed::operator/(const Fixed &rhs) const {
    std::cout << "Division operator called" << std::endl;
    return(Fixed(this->_fixedPointValue / rhs._fixedPointValue));
}

Fixed & Fixed::operator++(void){
    std::cout << "Pre-Increment operator called" << std::endl;
    this->_fixedPointValue += 1;
    return *this;
}

Fixed   Fixed::operator++(int){
    std::cout << "Post-Increment operator called" << std::endl;
    Fixed   clone(*this);
    ++*this;
    return clone;
}

Fixed & Fixed::operator--(void){
    std::cout << "Pre-Decrement operator called" << std::endl;
    this->_fixedPointValue -= 1;
    return *this;
}

Fixed   Fixed::operator--(int){
    std::cout << "Post-Decrement operator called" << std::endl;
    Fixed   clone(*this);
    --*this;
    return clone;
}

int Fixed::getRawBits() const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(const int value) {
    this->_fixedPointValue = value;}

float Fixed::toFloat(void) const {
    return ((float)(this->_fixedPointValue) / (float)(1 << this->_fractBits));
}

int Fixed::toInt(void) const {
    return (this->_fixedPointValue >> this->_fractBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.getRawBits();
    return os;
}

Fixed &max(Fixed &a, Fixed &b) {
    return a < b ? b : a;
}

const Fixed &max(const Fixed &a, const Fixed &b) {
    return a < b ? b : a;
}

Fixed &min(Fixed &a, Fixed &b) {
    return a > b ? b : a;
}

const Fixed &min(const Fixed &a, const Fixed &b) {
    return a > b ? b : a;
}

