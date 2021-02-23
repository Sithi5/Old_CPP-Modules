#include "Pony.hpp"

Pony::Pony(std::string name, std::string color, int age, std::string death) : _name(name), _color(color), _age(age), _death(death)
{
	std::cout << "The pony " << this->_name << " just arrived !" << std::endl;
}

Pony::~Pony(void)
{
	std::cout << "The pony " << this->_name << " died : " << std::endl
			  << this->_death << " at the age of " << this->_age << " :'(." << std::endl;
}

void Pony::setName(std::string name)
{
	this->_name = name;
}

void Pony::setColor(std::string color)
{
	this->_color = color;
}

void Pony::setAge(int age)
{
	this->_age = age;
}

void Pony::setDeath(std::string death)
{
	this->_death = death;
}

int Pony::getAge(void) { return (this->_age); }

std::string Pony::getName(void) { return (this->_name); }

std::string Pony::getColor(void) { return (this->_color); }

std::string Pony::getDeath(void) { return (this->_death); }

void Pony::talk(void) const
{
	std::cout << "Hello ! My name is " << this->_name << " I'm a " << this->_color << " pony and I am " << this->_age << " y old :)." << std::endl;
}