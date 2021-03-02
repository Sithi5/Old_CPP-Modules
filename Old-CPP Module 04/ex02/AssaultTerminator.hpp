#ifndef TEST_ASSAULTTERMINATOR_HPP
# define TEST_ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"
# include <iostream>

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator(void);
	AssaultTerminator(AssaultTerminator const &copy);
	virtual ~AssaultTerminator(void);
	AssaultTerminator &	operator=(AssaultTerminator const &rhs);

	virtual ISpaceMarine* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;
};

#endif