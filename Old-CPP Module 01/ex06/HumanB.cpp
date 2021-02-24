#include "HumanB.hpp"

HumanB::HumanB(std::string const name): _name(name) {}
HumanB::~HumanB(void){}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attack with his " << this->_weapon->getType() << std::endl;
}

Weapon		*HumanB::getWeapon(void) const { return (this->_weapon); }

void		HumanB::setWeapon(Weapon &weapon){ this->_weapon = &weapon; }

std::string	HumanB::getName(void) const { return (this->_name); }

void		HumanB::setName(std::string const name) { this->_name = name; }
