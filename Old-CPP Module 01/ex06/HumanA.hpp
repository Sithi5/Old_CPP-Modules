#ifndef OLD_CPP_MODULE_HUMANA_HPP
# define OLD_CPP_MODULE_HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string const name, Weapon &weapon);
		~HumanA(void);

		void		attack(void) const;

		Weapon		&getWeapon(void) const;
		std::string	getName(void) const;
		void		setName(std::string const name);
	
	private:
		std::string	_name;
		Weapon		&_weapon;
};

#endif