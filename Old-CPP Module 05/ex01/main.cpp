#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat boss("Denis", 1);
	Form form("SpringBreak form", 1, 1);

	form.beSigned(boss);
	std::cout << "form state = " << form << std::endl;

}