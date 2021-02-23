#include "Zombie.hpp"


Zombie::Zombie(std::string name, std::string type): _type(type), _name(name) {}

Zombie::~Zombie() {}

void Zombie::setType(std::string type){this->_type = type;}
std::string Zombie::getType(void){return this->_type;}

void Zombie::setName(std::string name){this->_name = name;}
std::string Zombie::getName(void){return this->_name;}

void Zombie::advert(void) const {
    std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss ..." << std::endl;
}