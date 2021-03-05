#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade)
	: _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy.getName()) { *this = copy; }

Bureaucrat::~Bureaucrat()
{
	std::cout << getName() << " has been fired." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Bureaucrat::incrementGrade(void)
{
	std::cout << this->getName() << " va se faire promouvoir." << std::endl;
	if (getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	std::cout << this->getName() << " va se faire retrograder." << std::endl;
	if (getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form *form) const
{
	if (form->isIsSigned())
	{
		std::cout << this << " cannot sign " << form << " because the form is already signed." << std::endl;
	}
	else if (form->getSignedGrade() < this->getGrade())
	{
		std::cout << this << " cannot sign " << form << " because it's grade is too low." << std::endl;
	}
	else
	{
		std::cout << this << " signs " << form << std::endl;
	}
	form->beSigned(*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << "<" << rhs.getName() << "> bureaucrat grade <" << rhs.getGrade() << ">" << std::endl;
	return o;
}
