#include "Peon.hpp"

Peon::Peon(void)	{
	std::cout << "This should not happend! What is this Peonery?" << std::endl;
}

Peon::Peon(std::string name):	Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &copy)	{
	*this = copy;
}

Peon::~Peon(void){
	std::cout << "Bleuark..." << std::endl;
}

Peon	&	Peon::operator=(const Peon	&rhs)	{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
	}
	return (*this);
}

void			Peon::getPolymorphed(void) const {
	std::cout << this->_name << " was just polymorphed into a pink pony!" << std::endl;
}

std::ostream &	operator<<(std::ostream & o, Peon const & rhs)	{
	o << "I'm " << rhs.getName() << " and I like otters!" << std::endl;
	return o;
}