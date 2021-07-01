
#ifndef TEST_PRESIDENTIALPARDONFORM_HPP
#define TEST_PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(const std::string &target);

	PresidentialPardonForm(PresidentialPardonForm const &copy);

	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	virtual void execute(Bureaucrat const &executor) const;

private:
	PresidentialPardonForm();

	std::string _target;
};

#endif //TEST_PRESIDENTIALPARDONFORM_HPP
