#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat boss("Denis", 1);
	Form form("SpringBreak form", 1, 1);
	std::cout << "form state = " << form << std::endl;

	form.beSigned(boss);
	std::cout << "form state = " << form << std::endl;

	Bureaucrat test("Bob", 51);
	Form test1("SpringTest form", 52, 50);
	std::cout << "form state = " << form << std::endl;

	try
	{
		form.beSigned(boss);
	}
	catch (Form::AlreadySignedException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form test2("Copy form", -1, 1);
	}
	catch (Form::GradeTooHighException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form test3("Copycat form", 250, 1);
	}
	catch (Form::GradeTooLowException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
}