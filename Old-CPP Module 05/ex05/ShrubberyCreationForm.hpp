#ifndef TEST_SHRUBBERYCREATIONFORM_HPP
# define TEST_SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>
#include <ostream>

class ShrubberyCreationForm : public Form {
public:
    ShrubberyCreationForm(const std::string &target);

    ShrubberyCreationForm(ShrubberyCreationForm const &copy);

    virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

    virtual void execute(Bureaucrat const &executor) const;

private:
    ShrubberyCreationForm();

    std::string _target;
};


#endif //TEST_SHRUBBERYCREATIONFORM_HPP
