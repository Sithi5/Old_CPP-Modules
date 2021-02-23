#include "Zombie.hpp"


Zombie::Zombie(std::string type, std::string name): _type(type), _name(name) {}

Zombie::~Zombie() {}

void Zombie::announce(void) {
    std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss ..." << std::endl;
}