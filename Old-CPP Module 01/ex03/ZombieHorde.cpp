#include "ZombieHorde.hpp"
#include <stdlib.h>

ZombieHorde::ZombieHorde(int n) : _n(n), _horde(new Zombie[n])
{
	for (int i = 0; i < n; i++)
	{
		this->_horde[i].setName(this->generateRandomName());
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[] this->_horde;
}

Zombie *ZombieHorde::getHorde(void) { return (this->_horde); }

void ZombieHorde::setHorde(Zombie *horde) { this->_horde = horde; }

void ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->_n; i++)
	{
		this->_horde[i].announce();
	}
}

std::string ZombieHorde::generateRandomName(void) const
{
	std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string random_name = "";
	int name_len = rand() % 6 + 4;
	for (int i = 0; i < name_len; i++)
	{
		random_name += (alphabet[rand() % alphabet.length()]);
	}
	return random_name;
}