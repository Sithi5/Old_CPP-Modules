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
    (void) rhs;
	return *this;
}

Form *Intern::makeShrubberyCreationForm(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

Form *Intern::makePresidentialPardonForm(std::string const &target) {
    return new PresidentialPardonForm(target);
}

Form *Intern::makeRobotomyRequestForm(std::string const &target) {
    return new RobotomyRequestForm(target);
}

Form * Intern::makeForm(std::string const &name, std::string const &target){
    Form * (Intern::*p[3])(std::string const & target) = {
            &Intern::makeShrubberyCreationForm,
            &Intern::makePresidentialPardonForm,
            &Intern::makeRobotomyRequestForm,
    };
    std::string key[3] = {
            "shrubbery creation",
            "presidential pardon",
            "robotomy request",
    };
    int key_size = sizeof(key) / sizeof(*key);

    for (int i = 0; i < key_size; i++)
	{
		if (!(key[i].compare(name)))
		{
            std::cout << "i is : " << i << std::endl;
            std::cout << "name is : " << name << std::endl;
			Form *newForm = (this->*p[i])(target);
			std::cout << "Intern creates " << newForm->getName() << std::endl;
			return newForm;
		}
	}
    std::cout << "Intern could not create the form : " << name << std::endl;
    return NULL;
}

