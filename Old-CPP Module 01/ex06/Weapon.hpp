#ifndef OLD_CPP_MODULE_WEAPON_HPP
# define OLD_CPP_MODULE_WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		Weapon(std::string const type);
		~Weapon(void);

		std::string getType(void) const;
		void		setType(std::string const type);

	private:
		std::string _type;
};

#endif