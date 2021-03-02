#include "Character.hpp"

Character::Character(std::string const & name): _name(name), _ap(40), _weapon(NULL) {}

Character::Character(Character const &copy) {
	*this = copy;
}

Character::~Character() {}

Character &		Character::operator=(Character const &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_ap = rhs.getAP();
		this->_weapon = rhs.getWeapon();
	}
	return *this;
}

void Character::recoverAP() {
	if (this->_ap < 40)
	{
		this->_ap += 10;
	}
}
void Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

void Character::attack(Enemy *enemy)
{
	if (this->_weapon != NULL && this->_ap >= this->_weapon->getAPCost())
	{
		std::cout << this->_name << " attaque " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
		this->_ap -= this->_weapon->getAPCost();
		this->_weapon->attack();
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() <= 0)
		{
			enemy->~Enemy();
		}
	}
}

std::ostream & operator<<(std::ostream & o, Character &charac) {
	o << charac.getName() << " has " << charac.getAP() << " AP and ";
	if (charac.getWeapon() != NULL)
	{
		o << "carries a " << charac.getWeapon()->getName();
	}
	else
	{
		o << "is unarmed";
	}
	o << std::endl;
	return o;
}

std::string Character::getName() const {
	return this->_name;
}

int			Character::getAP() const {
	return this->_ap;
}

AWeapon		*Character::getWeapon() const {
	return this->_weapon;
}

void		Character::setName(const std::string name) {
	this->_name = name;
}

void		Character::setAP(const int ap) {
	this->_ap = ap;
}

void		Character::setWeapon(AWeapon *weapon) {
	this->_weapon = weapon;
}