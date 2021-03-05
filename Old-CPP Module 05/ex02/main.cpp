#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Form *schrub = new ShrubberyCreationForm("my_first_trees");
	Bureaucrat boss("titi",10);

	boss.signForm(schrub);
	schrub->execute(boss);
}