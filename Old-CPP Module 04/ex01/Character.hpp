#ifndef OLD_CPP_MODULES_CHARACTER_HPP
# define OLD_CPP_MODULES_CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	public:
		Character(std::string const & name);
		Character(Character const &copy);
		virtual ~Character();

		Character &		operator=(Character const &rhs);

		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);

		std::string getName() const;
		int			getAP() const;
		AWeapon		*getWeapon() const;
		void		setName(const std::string name);
		void		setAP(const int ap);
		void		setWeapon(AWeapon *weapon);

	protected:
		std::string	_name;
		int			_ap;
		AWeapon		*_weapon;

	private:
		Character(void);
};

std::ostream & operator<<(std::ostream & o, Character &charac);

#endif