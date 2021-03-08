#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("Shrubbery", 145, 10), _target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): Form("Shrubbery", 145, 10) {
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return (*this);
}


void ShrubberyCreationForm::execute(const Bureaucrat &executor) {
    Form::execute(executor);
    std::ofstream ofs((this->_target + "_shrubbery").c_str(), std::ios::out);
    if (!ofs.is_open()) {
        throw std::runtime_error("ShrubberyCreationForm : execute - error when opening a file.");
    }
    ofs << "               ,@@@@@@@,\n"
           "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
           "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
           "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
           "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
           "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
           "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
           "       |o|        | |         | |\n"
           "       |.|        | |         | |\n"
           "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
    ofs.close();
}


