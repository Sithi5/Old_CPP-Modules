#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Form *schrub = new ShrubberyCreationForm("my_first_trees");
	Form *presi = new PresidentialPardonForm("HELP");
	Form *schrub = new RobotomyRequestForm("ALED");
	Bureaucrat boss("titi", 10);
	Bureaucrat larbin("titi", 150);
	try
	{
		schrub->execute(boss);
	}
	catch (Form::UnsignedFormException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	boss.signForm(schrub);
}