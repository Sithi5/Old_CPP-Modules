#ifndef EX04_STRIPMINER_HPP
# define EX04_STRIPMINER_HPP

#include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser
{
public:
	StripMiner(void);
	StripMiner(StripMiner const &copy);
	virtual ~StripMiner(void);
	StripMiner &	operator=(StripMiner const &rhs);

	virtual void mine(IAsteroid *asteroid);
};


#endif