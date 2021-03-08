#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main(void)
{
	Bureaucrat boss("The BOSS", 10);
	Bureaucrat larbin("M larbin", 150);
	Intern intern;
	OfficeBlock block_one(&larbin, &boss, &intern);
    OfficeBlock block_two;

	try{
        block_one.doBureaucracy("shrubbery creation","my_first_trees");
	}
    catch (OfficeBlock::OfficeBureaucrateUnqualified const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try{
        block_two.doBureaucracy("shrubbery creation","my_first_trees");
    }
    catch (OfficeBlock::OfficeBlockMissSomeone const &e){
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat good_guy("Good guy", 15);
        block_two.setFirstBureaucrat(&good_guy);
        block_two.setSecondBureaucrat(&boss);
        block_two.setIntern(&intern);
        block_two.doBureaucracy("shrubbery creation", "my_first_trees");
        block_two.doBureaucracy("presidential pardon", "boss");
        block_two.doBureaucracy("robotomy request", "robot work");
    }
    catch(std::exception const &e){
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
//
//int main()
//{
//    Intern idiotOne;
//    Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
//    Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
//    OfficeBlock ob;
//    ob.setIntern(&idiotOne);
//    ob.setFirstBureaucrat(&bob);
//    ob.setSecondBureaucrat(&hermes);
//    try
//    {
//        ob.doBureaucracy("mutant pig termination", "Pigley");
//    }
//    catch (OfficeBlock::OfficeInternIsDumm &e)
//    {
//        std::cerr << e.what() << std::endl;
///* specific known error happens, say something */
//    }
//    catch (std::exception & e)
//    {
//        std::cerr << "unknow exception : "<< e.what() << std::endl;
///* oh god, unknown error, what to do ?! */
//    }
//}