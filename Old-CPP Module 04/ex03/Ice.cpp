#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) : AMateria(copy.getType()) {
    *this = copy;
}

Ice &Ice::operator=(Ice const &rhs) {
    (void) rhs;
    return *this;
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    this->setXp(this->getXP() + 10);
}

AMateria *Ice::clone() const {
    return (new Ice(*this));
}


