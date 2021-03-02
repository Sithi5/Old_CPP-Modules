#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void): Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & copy): Enemy(copy) {
	*this = copy;
}

RadScorpion::~RadScorpion(void) {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion & RadScorpion::operator=(RadScorpion const &rhs) {
	if (this != &rhs)
	{
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
	}
	return *this;
}