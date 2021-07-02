#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : _first_bureaucrat(NULL), _second_bureaucrat(NULL), _intern(NULL) {}

OfficeBlock::OfficeBlock(Bureaucrat *first_bureaucrat, Bureaucrat *second_bureaucrat, Intern *intern)
    : _first_bureaucrat(first_bureaucrat), _second_bureaucrat(second_bureaucrat), _intern(intern)
{
}

OfficeBlock::~OfficeBlock()
{
}

Bureaucrat *OfficeBlock::getFirstBureaucrat() const
{
    return this->_first_bureaucrat;
}

void OfficeBlock::setFirstBureaucrat(Bureaucrat *firstBureaucrat)
{
    this->_first_bureaucrat = firstBureaucrat;
}

Bureaucrat *OfficeBlock::getSecondBureaucrat() const
{
    return this->_second_bureaucrat;
}

void OfficeBlock::setSecondBureaucrat(Bureaucrat *secondBureaucrat)
{
    this->_second_bureaucrat = secondBureaucrat;
}

Intern *OfficeBlock::getIntern() const
{
    return this->_intern;
}

void OfficeBlock::setIntern(Intern *intern)
{
    this->_intern = intern;
}

void OfficeBlock::doBureaucracy(const std::string &name, const std::string &target)
{
    if (!this->getFirstBureaucrat() || !this->getSecondBureaucrat() || !this->getIntern())
    {
        throw OfficeBlock::OfficeBlockMissSomeone();
    }
    try
    {
        Form *new_form = this->getIntern()->makeForm(name, target);
        try
        {
            new_form->beSigned(*(this->getFirstBureaucrat()));
            new_form->execute(*(this->getSecondBureaucrat()));
            delete new_form;
        }

        catch (Form::AlreadySignedException)
        {
            delete new_form;
            throw OfficeBlock::OfficeOrganizationIsAMess();
        }
        catch (Form::GradeTooLowException)
        {
            delete new_form;
            throw OfficeBlock::OfficeBureaucrateUnqualified();
        }
        catch (Form::GradeTooHighException)
        {
            delete new_form;
            throw OfficeBlock::OfficeBureaucrateTooMuchqualified();
        }
        catch (Form::UnsignedFormException)
        {
            delete new_form;
            throw OfficeBlock::OfficeChaos();
        }
    }
    catch (Intern::InternIsDummException)
    {
        throw OfficeBlock::OfficeInternIsDumm();
    }
}

const char *OfficeBlock::OfficeBlockMissSomeone::what() const throw()
{
    return "The block is not full, cannot do bureaucracy.";
}

const char *OfficeBlock::OfficeInternIsDumm::what() const throw()
{
    return "The intern in the office block don't know how to do form ! Fire him!";
}

const char *OfficeBlock::OfficeOrganizationIsAMess::what() const throw()
{
    return "A bureaucrate tried to sign two time the same form, it's a mess !";
}

const char *OfficeBlock::OfficeBureaucrateUnqualified::what() const throw()
{
    return "A bureaucrate seems to be an idiot, he don't know how to sign !";
}

const char *OfficeBlock::OfficeBureaucrateTooMuchqualified::what() const throw()
{
    return "A bureaucrate seems to be too smart for his job.";
}

const char *OfficeBlock::OfficeChaos::what() const throw()
{
    return "Boss try to execute an unsigned form, this office is in chaos !";
}