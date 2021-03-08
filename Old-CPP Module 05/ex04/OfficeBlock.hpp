
#ifndef TEST_OFFICEBLOCK_HPP
#define TEST_OFFICEBLOCK_HPP

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock {
public:

    OfficeBlock();

    OfficeBlock(Bureaucrat *first_bureaucrat, Bureaucrat *second_bureaucrat, Intern *intern);

    virtual ~OfficeBlock();


    Bureaucrat *getFirstBureaucrat() const;

    void setFirstBureaucrat(Bureaucrat *firstBureaucrat);

    Bureaucrat *getSecondBureaucrat() const;

    void setSecondBureaucrat(Bureaucrat *secondBureaucrat);

    Intern *getIntern() const;

    void setIntern(Intern *intern);

    void doBureaucracy(std::string const &name, std::string const &target);

    class OfficeBlockMissSomeone : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class OfficeInternIsDumm : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class OfficeOrganizationIsAMess : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class OfficeBureaucrateUnqualified : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class OfficeBureaucrateTooMuchqualified : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class OfficeChaos : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

private:
    Bureaucrat *_first_bureaucrat;
    Bureaucrat *_second_bureaucrat;
    Intern *_intern;
};


#endif //TEST_OFFICEBLOCK_HPP
