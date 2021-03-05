#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat boss("Denis", 1);
	std::cout << boss;
	Bureaucrat larbin("Stagiaire Jean", 150);
	std::cout << larbin;
	Bureaucrat faineant("Stagiaire Pala", 150);
	std::cout << faineant;
	try
	{
		Bureaucrat megaboss("Xavier", 0);
	}
	catch (Bureaucrat::GradeTooHighException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat megaboss("Paul Emploi", 200);
	}
	catch (Bureaucrat::GradeTooLowException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		boss.decrementGrade();
		faineant.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		larbin.incrementGrade();
		boss.incrementGrade();
		boss.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << boss;
	std::cout << larbin;
	std::cout << faineant;
}