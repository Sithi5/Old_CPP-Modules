#ifndef OLD_CPP_MODULES_VICTIM_HPP
# define OLD_CPP_MODULES_VICTIM_HPP

# include <iostream>

class Victim {
	public:
		Victim(std::string name);
		Victim(Victim const &copy);
		virtual ~Victim(void);

		Victim &	operator=(const Victim &rhs);
		
		std::string	getName(void) const;
		void		setName(std::string name);

		virtual void	getPolymorphed(void) const;

	protected:
		Victim(void);
		std::string	_name;
};

std::ostream &	operator<<(std::ostream & o, Victim const & rhs);

#endif