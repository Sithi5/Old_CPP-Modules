#ifndef EX03_FORM_HPP
#define EX03_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(const std::string &name, const int signedGrade, const int execGrade);

	Form(Form const &copy);

	virtual ~Form();

	Form &operator=(Form const &rhs);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
    class UnsignedFormException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

	const std::string &getName() const;

	bool isIsSigned() const;

	int getSignedGrade() const;

	int getExecGrade() const;

	void beSigned(Bureaucrat const &bureaucrat);

    virtual void execute(Bureaucrat const & executor);

private:
	Form();

	std::string const _name;
	bool _is_signed;
	int const _signed_grade;
	int const _exec_grade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //EX03_FORM_HPP
