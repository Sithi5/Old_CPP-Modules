#include "AWeapon.hpp"

AWeapon::AWeapon(void) {
	std::cout << "Void constructor called. Unexpected..." << std::endl;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
							: _name(name), _apcost(apcost), _damage(damage) {}

AWeapon::AWeapon(AWeapon const &copy) {
	*this = copy;
}

AWeapon::~AWeapon(void) {}

AWeapon & AWeapon::operator=(const AWeapon &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_apcost = rhs.getAPCost();
		this->_damage = rhs.getDamage();
	}
	return (*this);
}

std::string	AWeapon::getName() const {
	return (this->_name);
}

void		AWeapon::setName(std::string name) {
	this->_name = name;
}

int			AWeapon::getAPCost() const {
	return (this->_apcost);
}

void		AWeapon::setAPCost(int apcost) {
	this->_apcost = apcost;
}

int			AWeapon::getDamage() const {
	return (this->_damage);
}

void		AWeapon::setDamage(int damage) {
	this->_damage = damage;
}