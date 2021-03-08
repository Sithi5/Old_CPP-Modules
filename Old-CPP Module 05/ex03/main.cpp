#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat boss("The BOSS", 10);
	Bureaucrat larbin("M larbin", 150);
	Intern intern;
    Form *pardon = intern.makeForm("presidential pardon", "HELP");
    Form *schrub = intern.makeForm("shrubbery creation", "my_first_trees");
    Form *robo = intern.makeForm("robotomy request", "ALED");

	try
	{
		schrub->execute(boss);
	}
	catch (Form::UnsignedFormException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	boss.signForm(schrub);
	try
	{
		larbin.signForm(robo);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "end" << std::endl;
	try
	{
		boss.signForm(schrub);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	boss.signForm(pardon);
	boss.signForm(robo);
	schrub->execute(boss);
	pardon->execute(boss);
	robo->execute(boss);
	return (0);
}