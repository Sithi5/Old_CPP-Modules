#ifndef OLD_CPP_MODULES_PEON_HPP
# define OLD_CPP_MODULES_PEON_HPP

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim{ 
	public:
		Peon(std::string name);
		Peon(Peon const &copy);
		virtual ~Peon(void);

		Peon &	operator=(const Peon &rhs);
		
		virtual void	getPolymorphed(void) const;

	private:
		Peon(void);
};

std::ostream &	operator<<(std::ostream & o, Peon const & rhs);

#endif