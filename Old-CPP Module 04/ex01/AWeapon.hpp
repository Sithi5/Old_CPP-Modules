#ifndef OLD_CPP_MODULES_AWEPON_HPP
# define OLD_CPP_MODULES_AWEPON_HPP

# include <iostream>

class AWeapon
{
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const &copy);
		virtual ~AWeapon();

		AWeapon &	operator=(AWeapon const &rhs);

		std::string	getName() const;
		int			getAPCost() const;
		int			getDamage() const;
		void		setName(const std::string name);
		void		setAPCost(const int apcost);
		void		setDamage(const int damage);
		virtual void attack(void) const = 0;
	
	protected:
		std::string _name;
		int			_apcost;
		int			_damage;

	private:
		AWeapon(void);
};

#endif