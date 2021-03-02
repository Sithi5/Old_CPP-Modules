#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void): Enemy(170, "SuperMutant") {
	std::cout << "Gaaah. Break everything !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & copy): Enemy(copy) {
	*this = copy;
}

SuperMutant::~SuperMutant(void) {
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant & SuperMutant::operator=(SuperMutant const &rhs) {
	if (this != &rhs)
	{
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return *this;
}

void		SuperMutant::takeDamage(int damage) {
	int trueDamage = damage - 3;

	if (trueDamage > 0)
	{
		this->_hp -= trueDamage;
	}
}