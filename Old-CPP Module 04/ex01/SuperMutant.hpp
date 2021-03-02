#ifndef OLD_CPP_MODULES_SUPERMUTANT_HPP
# define OLD_CPP_MODULES_SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant: public Enemy
{
	public:
		SuperMutant(void);
		SuperMutant(SuperMutant const &copy);
		virtual ~SuperMutant();

		SuperMutant &	operator=(SuperMutant const &rhs);

		virtual void takeDamage(int);
};

#endif