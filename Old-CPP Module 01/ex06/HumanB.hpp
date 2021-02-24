#ifndef OLD_CPP_MODULE_HUMANB_HPP
# define OLD_CPP_MODULE_HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string const name);
		~HumanB(void);

		void	attack(void) const;

		Weapon		*getWeapon(void) const;
		void		setWeapon(Weapon &weapon);
		std::string	getName(void) const;
		void		setName(std::string const name);
	
	private:
		std::string	_name;
		Weapon	*_weapon;
};

#endif