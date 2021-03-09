
#include "Litteral.hpp"

Litteral::Litteral(std::string &input) : _input(input) {}

Litteral::Litteral() {}

Litteral::Litteral(const Litteral &cpy) {
    *this = cpy;
}

Litteral &Litteral::operator=(const Litteral &rhs) {
    if (this != &rhs) {
        this->_input = rhs._input;
    }
    return *this;
}


Litteral::~Litteral() {

}

Litteral::operator char() {
    return 0;
}

Litteral::operator int() {
    return 0;
}

Litteral::operator float() {
    return 0;
}

Litteral::operator double() {
    return 0;
}

