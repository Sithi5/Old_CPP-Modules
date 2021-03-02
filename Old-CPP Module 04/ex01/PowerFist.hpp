#ifndef OLD_CPP_MODULES_POWERFIST_HPP
# define OLD_CPP_MODULES_POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	public:
		PowerFist(void);
		PowerFist(PowerFist const &copy);
		virtual ~PowerFist();

		PowerFist &	operator=(PowerFist const &rhs);

		virtual void attack(void) const;
};

#endif