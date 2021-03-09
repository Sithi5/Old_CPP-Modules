
#include "Litteral.hpp"

Litteral::Litteral(std::string input): _input(input) {}

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
