#ifndef OLD_CPP_MODULES_SORCERER_HPP
# define OLD_CPP_MODULES_SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer {
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const &copy);
		virtual ~Sorcerer(void);

		Sorcerer &	operator=(const Sorcerer &rhs);
		
		std::string	getName(void) const;
		void		setName(std::string name);
		std::string	getTitle(void) const;
		void		setTitle(std::string title);

		void		polymorph(Victim const &vic) const;

	private:
		Sorcerer(void);
		std::string	_name;
		std::string	_title;
};

std::ostream &	operator<<(std::ostream & o, Sorcerer const & rhs);

#endif