#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) {
    *this = copy;
}

Ice &Ice::operator=(Ice const &rhs) {
    (void) rhs;
    return *this;
}

void Ice::use(ICharacter &target) {
    std::cout << this->getType() << " : \"* shoots an ice bolt at " << target << " *\"" << std::endl;
    this->setXp(this->getXP() + 10);
}

Ice *Ice::clone() const {
    return (new Ice(*this));
}


