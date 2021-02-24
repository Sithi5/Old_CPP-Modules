#ifndef OLD_CPP_MODULE_BRAIN_HPP
# define OLD_CPP_MODULE_BRAIN_HPP

# include <iostream>
# include <string>
# include <sstream>

class Brain
{
	public:
		Brain( void );
		~Brain( void );

		std::string identify( void ) const;

		std::string getSomething( void ) const;
		void setSomething(std::string);

	private:
		std::string _something;
};
#endif
