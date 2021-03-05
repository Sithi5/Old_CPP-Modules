#include "Form.hpp"

Form::Form(const std::string &name, const int signedGrade, const int execGrade)
        : _name(name), _is_signed(0),
          _signed_grade(signedGrade),
          _exec_grade(execGrade) {
    if (this->_signed_grade < 1 || this->_exec_grade < 1) {
        throw Form::GradeTooLowException();
    } else if (this->_signed_grade > 150 || this->_exec_grade > 150) {
        throw Form::GradeTooHighException();
    }
}

Form::Form(Form const &copy) : _exec_grade(copy.getExecGrade()), _signed_grade(copy.getSignedGrade()),
                               _name(copy.getName()) {
    *this = copy;
}

Form::~Form() {
    std::cout << getName() << " has been thrown in the trash bin." << std::endl;
}

Form &Form::operator=(Form const &rhs) {
    if (this != &rhs) {
        this->_is_signed = rhs._is_signed;
    }
    return (*this);
}

const std::string &Form::getName() const {
    return this->_name;
}

bool Form::isIsSigned() const {
    return this->_is_signed;
}

int Form::getSignedGrade() const {
    return this->_signed_grade;
}

int Form::getExecGrade() const {
    return this->_exec_grade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException) {
    if (bureaucrat.getGrade() > this->getSignedGrade()) {
        throw Form::GradeTooLowException();
    } else {
        bureaucrat.signForm(*this);
    }
}


const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}


std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "_name: " << form.getName() << " _is_signed: " << form.isIsSigned() << " _signed_grade: "
       << form.getSignedGrade()
       << " _exec_grade: " << form.getExecGrade();
    return os;
}

