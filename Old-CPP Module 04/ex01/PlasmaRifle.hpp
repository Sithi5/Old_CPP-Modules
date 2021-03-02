#ifndef OLD_CPP_MODULES_PLASMARIFLE_HPP
# define OLD_CPP_MODULES_PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle const &copy);
		virtual ~PlasmaRifle();

		PlasmaRifle &	operator=(PlasmaRifle const &rhs);

		virtual void attack(void) const;
};

#endif