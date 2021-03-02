#include "Enemy.hpp"

Enemy::Enemy(void) {
	std::cout << "Can't create empty ennemy." << std::endl;
}

Enemy::Enemy(int hp, std::string const & type): _hp(hp), _type(type) {}

Enemy::Enemy(Enemy const & copy) {
	*this = copy;
}

Enemy::~Enemy(void) {}

Enemy & Enemy::operator=(Enemy const &rhs) {
	if (this != &rhs)
	{
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return *this;
}

std::string	Enemy::getType(void) const {
	return this->_type;
}

int			Enemy::getHP(void) const {
	return this->_hp;
}

void		Enemy::setType(std::string type) {
	this->_type = type;
}
void		Enemy::setHP(int hp) {
	this->_hp = hp;
}

void		Enemy::takeDamage(int damage) {
	if (damage > 0)
	{
		this->_hp -= damage;
	}
}