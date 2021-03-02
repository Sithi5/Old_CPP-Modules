#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void): AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &copy): AWeapon(copy) {
	*this = copy;
}

PlasmaRifle::~PlasmaRifle(void) {}

PlasmaRifle & PlasmaRifle::operator=(const PlasmaRifle &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_apcost = rhs.getAPCost();
		this->_damage = rhs.getDamage();
	}
	return (*this);
}

void		PlasmaRifle::attack(void) const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}