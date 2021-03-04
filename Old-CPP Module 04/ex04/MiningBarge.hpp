#ifndef	EX04_MININGBARGE_HPP
# define EX04_MININGBARGE_HPP

# include "IMiningLaser.hpp"
# include "IAsteroid.hpp"

class MiningBarge
{
public:
	MiningBarge(void);
	MiningBarge(MiningBarge const &copy);
	virtual ~MiningBarge(void);
	MiningBarge &	operator=(MiningBarge const &rhs);
	void equip(IMiningLaser*);
	void mine(IAsteroid*) const;

private:
    IMiningLaser *_lasers[4];
};

#endif