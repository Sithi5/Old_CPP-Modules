#include "AMateria.hpp"

AMateria::AMateria() : _type("default"), _xp(0) {}

AMateria::AMateria(const std::string &type) : _type(type), _xp(0) {}

AMateria::~AMateria() {
}

std::string const &AMateria::getType() const {
    return this->_type;
}

unsigned int AMateria::getXP() const {
    return this->_xp;
}

void AMateria::use(ICharacter &target) {
    (void) target;
    this->setXp(this->getXP() + 10);
}

void AMateria::setXp(unsigned int xp) {
    this->_xp = xp;
}


