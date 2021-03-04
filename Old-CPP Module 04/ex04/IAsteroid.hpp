#ifndef EX04_IASTEROID_HPP
# define EX04_IASTEROID_HPP

#include <iostream>

class DeepCoreMiner;

class StripMiner;

class IAsteroid
{
public:
	virtual ~IAsteroid() {}
	virtual std::string beMined(DeepCoreMiner *dcminer) const = 0;
	virtual std::string beMined(StripMiner *sminer) const = 0;
	virtual std::string getName() const = 0;
};

#endif