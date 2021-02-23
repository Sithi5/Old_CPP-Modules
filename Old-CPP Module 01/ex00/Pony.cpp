#include "Pony.hpp"

Pony::Pony(std::string name, std::string color, int age, std::string death): _name(name), _color(color), _age(age), _death(death) {
    std::cout << "The pony " << this->_name << " just arrived !" << std::endl;
}

Pony::~Pony(void) {
    std::cout << "The pony " << this->_name << " died : "<< std::endl << this->_death << " at the age of " << this->_age << " :'(." << std::endl;
}

void Pony::talk(void) const {
    std::cout << "Hello ! My name is " << this->_name << " I'm a " << this->_color << " pony and I am " << this->_age << " y old :)." << std::endl;
}