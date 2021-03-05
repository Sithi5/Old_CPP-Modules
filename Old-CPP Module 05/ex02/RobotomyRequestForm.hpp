
#ifndef TEST_ROBOTOMYREQUESTFORM_HPP
#define TEST_ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(const std::string &target);

	RobotomyRequestForm(RobotomyRequestForm const &copy);

	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	virtual void execute(Bureaucrat const &executor);

private:
	RobotomyRequestForm();

	std::string _target;
};

#endif //TEST_ROBOTOMYREQUESTFORM_HPP
