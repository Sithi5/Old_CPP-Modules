#include "Human.hpp"

int     main(void){
    Human human = Human();

    human.action("meleeAttack", "Geralt");
    human.action("intimidatingShout", "Alduin");
    human.action("rangedAttack", "Gimly");

    try{
        human.action("meleeattack", "Geralt");
        human.action("", "Geralt");
    }
    catch (std::exception &error){
        std::cerr << error.what() << std::endl;
    }

    return (0);
}