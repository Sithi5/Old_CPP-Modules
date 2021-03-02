#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)	{
	std::cout << "This should not happend! What is this sorcery?" << std::endl;
}

Sorcerer::Sorcerer(std::string name, std::string title)
	:	_name(name), _title(title) {
	std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &copy)	{
	*this = copy;
}

Sorcerer::~Sorcerer(void){
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer	&	Sorcerer::operator=(const Sorcerer	&rhs)	{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_title = rhs.getTitle();
	}
	return (*this);
}

std::string		Sorcerer::getName(void)	const{
	return this->_name;
}

void			Sorcerer::setName(std::string name)	{
	this->_name = name;
}

std::string		Sorcerer::getTitle(void)	const{
	return this->_title;
}

void			Sorcerer::setTitle(std::string title)	{
	this->_title = title;
}

void			Sorcerer::polymorph(const Victim & vic)	const{
	vic.getPolymorphed();
}

std::ostream &	operator<<(std::ostream & o, Sorcerer const & rhs)	{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and i like ponies!" << std::endl;
	return o;
}