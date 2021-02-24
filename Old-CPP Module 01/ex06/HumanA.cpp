#include "HumanA.hpp"

HumanA::HumanA(std::string const name, Weapon &weapon): _name(name), _weapon(weapon) {}
HumanA::~HumanA(void){}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attack with his " << this->_weapon.getType() << std::endl;
}

Weapon		&HumanA::getWeapon(void) const { return (this->_weapon); }

std::string	HumanA::getName(void) const { return (this->_name); }

void		HumanA::setName(std::string const name) { this->_name = name; }
