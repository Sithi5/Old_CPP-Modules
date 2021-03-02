#include "Victim.hpp"

Victim::Victim(void)	{
	std::cout << "This should not happend! What is this victimery?" << std::endl;
}

Victim::Victim(std::string name):	_name(name) {
	std::cout << "A random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const &copy)	{
	*this = copy;
}

Victim::~Victim(void){
	std::cout << "The victim " << this->_name << " died for no apparent reasons!" << std::endl;
}

Victim	&	Victim::operator=(const Victim	&rhs)	{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
	}
	return (*this);
}

std::string		Victim::getName(void)	const{
	return this->_name;
}

void			Victim::setName(std::string name)	{
	this->_name = name;
}

void			Victim::getPolymorphed(void) const {
	std::cout << this->_name << " was just polymorphed in a cute little sheep!" << std::endl;
}

std::ostream &	operator<<(std::ostream & o, Victim const & rhs)	{
	o << "I'm " << rhs.getName() << " and I like otters!" << std::endl;
	return o;
}