#ifndef EX03_INTERN_HPP
# define EX03_INTERN_HPP

#include "Form.hpp"

class Intern
{
public:
	Intern(void);
	Intern(Intern const &copy);
	virtual ~Intern(void);
	Intern & operator=(Intern const &rhs);

	Form * makeForm(std::string name, std::string target);
};

#endif