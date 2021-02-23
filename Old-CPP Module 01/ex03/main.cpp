#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main(void)
{
	ZombieHorde *horde = new ZombieHorde(5);
	horde->announce();
	delete horde;
}