#ifndef OLD_CPP_MODULES_ZOMBIEHORDE_HPP
#define OLD_CPP_MODULES_ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int n);
	~ZombieHorde();

	Zombie *getHorde(void);
	void setHorde(Zombie *Horde);
	void announce(void) const;
	int getN(void);
	void setN(int n);

private:
	int _n;
	Zombie *_horde;
	std::string generateRandomName(void) const;
};

#endif //OLD_CPP_MODULES_ZOMBIEHORDE_HPP
