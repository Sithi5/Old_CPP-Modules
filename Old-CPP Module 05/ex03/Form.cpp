#include "Form.hpp"

Form::Form(const std::string &name, const int signedGrade, const int execGrade)
	: _name(name), _is_signed(0),
	  _signed_grade(signedGrade),
	  _exec_grade(execGrade)
{
	if (getSignedGrade() < 1 || getExecGrade() < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (getSignedGrade() > 150 || getExecGrade() > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(Form const &copy) : _name(copy.getName()), _signed_grade(copy.getSignedGrade()), _exec_grade(copy.getExecGrade())
{
	*this = copy;
}

Form::~Form()
{
	std::cout << getName() << " has been thrown in the trash bin." << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_is_signed = rhs._is_signed;
	}
	return (*this);
}

const std::string &Form::getName() const
{
	return this->_name;
}

bool Form::isIsSigned() const
{
	return this->_is_signed;
}

int Form::getSignedGrade() const
{
	return this->_signed_grade;
}

int Form::getExecGrade() const
{
	return this->_exec_grade;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::AlreadySignedException::what() const throw()
{
	return "This is already signed";
}

const char *Form::UnsignedFormException::what() const throw()
{
    return "This is not signed";
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignedGrade())
	{
		throw Form::GradeTooLowException();
	}
	else if (this->_is_signed)
	{
		throw Form::AlreadySignedException();
	}
	else
	{
		this->_is_signed = true;
	}
}

void Form::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > this->getExecGrade())
        throw Form::GradeTooLowException();
    if (!this->isIsSigned())
        throw Form::UnsignedFormException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "_name: " << form.getName() << " _is_signed: " << form.isIsSigned() << " _signed_grade: "
	   << form.getSignedGrade()
	   << " _exec_grade: " << form.getExecGrade();
	return os;
}
