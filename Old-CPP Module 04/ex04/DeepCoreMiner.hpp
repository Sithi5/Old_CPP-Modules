#ifndef EX04_DEEPCOREMINER_HPP
# define EX04_DEEPCOREMINER_HPP

#include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser
{
public:
	DeepCoreMiner(void);
	DeepCoreMiner(DeepCoreMiner const &copy);
	virtual ~DeepCoreMiner(void);
	DeepCoreMiner &	operator=(DeepCoreMiner const &rhs);

	virtual void mine(IAsteroid *asteroid);
};


#endif