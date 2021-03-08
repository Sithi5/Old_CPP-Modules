#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void) {}
Intern::Intern(Intern const &copy) {
	*this = copy;
}
Intern::~Intern(void) {}
Intern & Intern::operator=(Intern const &rhs) {
	return *this;
}

Form * Intern::makeForm(std::string name, std::string target){
	Form tab[3] = {ShrubberyCreationForm(target), PresidentialPardonForm(target), RobotomyRequestForm(target)};
	Form *newForm = NULL;
	
	for (int i = 0; i < 3; i++)
	{
		if (!(tab[i].getName().compare(name)))
		{
			newForm = new Form(tab[i]);
			std::cout << "Intern creates " << newForm << std::endl;
			return newForm;
		}
	}
	return NULL;
}