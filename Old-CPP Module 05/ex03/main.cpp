#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Form *schrub = new ShrubberyCreationForm("my_first_trees");
	Form *pardon = new PresidentialPardonForm("HELP");
	Form *robo = new RobotomyRequestForm("ALED");
	Bureaucrat boss("The BOSS", 10);
	Bureaucrat larbin("M larbin", 150);
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