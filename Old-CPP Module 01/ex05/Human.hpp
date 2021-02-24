#ifndef OLD_CPP_MODULE_HUMAN_HPP
# define OLD_CPP_MODULE_HUMAN_HPP

# include <iostream>
# include "Brain.hpp"

class Human
{
	public:
		Human(void);
		~Human(void);

		const Brain	&getBrain( void ) const;
		std::string	identify( void ) const;
	
	private:
		const Brain _brain;
};
#endif