#include "Brain.hpp"

Brain::Brain( void ) : _something("something"){}
Brain::~Brain( void ){}

std::string Brain::identify( void ) const{
	std::stringstream hexaddress;

	hexaddress << this;
	return (hexaddress.str());
}

std::string Brain::getSomething( void ) const { return this->_something; }
void Brain::setSomething( std::string something ){ this->_something = something; }