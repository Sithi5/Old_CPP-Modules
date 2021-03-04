#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &copy) {
    *this = copy;
}

Cure &Cure::operator=(Cure const &rhs) {
    (void) rhs;
    return *this;
}

void Cure::use(ICharacter &target) {
    std::cout << this->getType() << " : \"* heals " << target.getName() << "'s wounds *\"" << std::endl;
    this->setXp(this->getXP() + 10);
}

Cure *Cure::clone() const {
    return (new Cure(*this));
}


