#include "PowerFist.hpp"

PowerFist::PowerFist(void): AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(PowerFist const &copy): AWeapon(copy) {
	*this = copy;
}

PowerFist::~PowerFist(void) {}

PowerFist & PowerFist::operator=(const PowerFist &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_apcost = rhs.getAPCost();
		this->_damage = rhs.getDamage();
	}
	return (*this);
}

void		PowerFist::attack(void) const {
	std::cout << "* pschhh... SBAM ! *" << std::endl;
}