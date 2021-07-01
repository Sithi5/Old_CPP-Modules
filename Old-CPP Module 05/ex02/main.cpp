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
		std::cerr << "error here : " << e.what() << std::endl;
	}
	boss.signForm(schrub);
	try
	{
        boss.executeForm(*schrub);
        larbin.signForm(robo);
	}
	catch (std::exception const &e)
	{
		std::cerr << "error2 here : " << e.what() << std::endl;
	}
	try
	{
		boss.signForm(schrub);
	}
	catch (std::exception const &e)
	{
		std::cerr << "error3 here : " << e.what() << std::endl;
	}
	boss.signForm(pardon);
	boss.signForm(robo);
	schrub->execute(boss);
    try
    {
        pardon->execute(boss);
    }
    catch (std::exception const &e)
    {
        std::cerr << "error4 here : " << e.what() << std::endl;
    }
	robo->execute(boss);



    std::cout << "\ndeleting the files."<<std::endl;
	delete schrub;
	delete pardon;
	delete robo;
	return (0);
}