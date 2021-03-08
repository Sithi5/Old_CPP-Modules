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

    class InternIsDummException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    Form * makeShrubberyCreationForm(std::string const &target);
    Form * makePresidentialPardonForm(std::string const &target);
    Form * makeRobotomyRequestForm(std::string const &target);
	Form * makeForm(std::string const &name, std::string const &target);
};

#endif