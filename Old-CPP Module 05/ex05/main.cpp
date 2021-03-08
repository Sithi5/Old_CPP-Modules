#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"
#include <stdlib.h>
#include <time.h>

std::string generateRandomName(void)
{
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string random_name = "";
    int name_len = rand() % 6 + 4;
    for (int i = 0; i < name_len; i++)
    {
        random_name += (alphabet[rand() % alphabet.length()]);
    }
    return random_name;
}

Bureaucrat *generateBureaucrate(){
    Bureaucrat *new_bureaucrate = new Bureaucrat(generateRandomName(), rand() % 149 + 1);
    return new_bureaucrate;
}


std::string generateRandomTaskName(){
    return std::string("T") + generateRandomName();
}

std::string generateRandomTask(){
    int random_num = rand() % 4;

    if (random_num == 0){
        return std::string("presidential pardon");
    }
//    else if (random_num == 1){
//        return std::string("shrubbery creation");
//    }
    else if (random_num == 3){
        return std::string("robotomy request");
    }
    else{
        return std::string("unknow request");
    }
}

int main(void) {
    srand(time(NULL));

    CentralBureaucracy central;

//    Test generation of intern
    try{
        OfficeBlock block_minus_20 = central.getBlockNb(-20);
        Form *pardon = block_minus_20.getIntern()->makeForm("presidential pardon", "HELP");
        std::cout << pardon->getName() << std::endl;
    }
    catch(CentralBureaucracy::OfficeDoesntExist const &e){
        std::cerr << e.what() << std::endl;
    }
    try{
        OfficeBlock block_200 = central.getBlockNb(200);
        Form *pardon = block_200.getIntern()->makeForm("presidential pardon", "HELP");
        std::cout << pardon->getName() << std::endl;
    }
    catch(CentralBureaucracy::OfficeDoesntExist const &e){
        std::cerr << e.what() << std::endl;
    }
    try{
        OfficeBlock block_19 = central.getBlockNb(19);
        Form *pardon = block_19.getIntern()->makeForm("presidential pardon", "HELP");
        std::cout << pardon->getName() << std::endl;
        OfficeBlock block_0 = central.getBlockNb(0);
        Form *pardon2 = block_0.getIntern()->makeForm("presidential pardon", "HELP");
        std::cout << pardon2->getName() << std::endl;
    }
    catch(CentralBureaucracy::OfficeDoesntExist const &e){
        std::cerr << e.what() << std::endl;
    }

//    Test filling some new bureaucrat
    std::cout << std::endl << std::endl << "FILLING CENTRAL WITH BUREAUCRAT" << std::endl<< std::endl;
    Bureaucrat *boss = new Bureaucrat("The BOSS", 10);
    Bureaucrat *boss2 = new Bureaucrat("The BOSS 2", 10);
    Bureaucrat *larbin = new Bureaucrat("M larbin", 150);
    Bureaucrat *good_guy = new Bureaucrat("Good guy", 15);
    try{
        central.hiring(larbin);
        central.hiring(boss);
        central.hiring(good_guy);
        central.hiring(boss2);
        central.queueUp("shrubbery creation", "my_first_trees");
        central.queueUp("shrubbery creation", "my_first_trees");
        central.executeAllTask();
    }
    catch(std::exception const &e){
        std::cerr << e.what() << std::endl;
    }

//    test generating new bureaucrat

    try{
        for (int i = 0; i < 45; i++){
            central.hiring(generateBureaucrate());
            std::cout <<std::endl;
        }
        for (int i = 0; i < 50; i++ ){
            central.queueUp(generateRandomTask(), generateRandomTaskName());
        }
        std::cout << std::endl << "EXECUTING ALL TASK" << std::endl << std::endl;
        central.executeAllTask();
    }
    catch(std::exception const &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl << "END OF MAIN, CALL TO CENTRALBLOCK DESTRUCTOR" << std::endl << std::endl;
}