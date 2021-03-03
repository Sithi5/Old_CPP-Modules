#ifndef TEST_TACTICALMARINE_HPP
# define TEST_TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"
# include <iostream>

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine(void);
	TacticalMarine(TacticalMarine const &copy);
	virtual ~TacticalMarine(void);
	TacticalMarine &	operator=(TacticalMarine const &rhs);

	virtual ISpaceMarine* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;

};

#endif