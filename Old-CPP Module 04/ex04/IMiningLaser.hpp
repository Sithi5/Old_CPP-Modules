#ifndef	EX04_IMININGLASER_HPP
# define EX04_IMININGLASER_HPP

#include "IAsteroid.hpp"

// class IAsteroid;

class IMiningLaser
{
public:
	virtual ~IMiningLaser() {}
	virtual void mine(IAsteroid *asteroid) = 0;
};

#endif