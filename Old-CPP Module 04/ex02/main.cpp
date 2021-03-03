#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
    ISpaceMarine* bob = new TacticalMarine();
    ISpaceMarine* jim = new AssaultTerminator();
    ISpaceMarine* dad = new TacticalMarine();
    ISpaceMarine* mom = new TacticalMarine();
    ISpaceMarine* nullos = NULL;
    ISquad* squad = new Squad;
    squad->push(bob);

    //    already in squad bob
    squad->push(bob);


    squad->push(jim);

//    pushing null spacemarine
    squad->push(nullos);


    //    already in squad jim
    squad->push(jim);

    squad->push(dad);
    squad->push(mom);


    std::cout << std::endl << "PRINTING ALL UNITS AND ATTACKS OF THE SQUAD" <<std::endl<<std::endl;

    for (int i = 0; i < squad->getCount(); i++)
    {
        std::cout << "Getting unit number : "<< i <<std::endl<<std::endl;
        ISpaceMarine* cur = squad->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
        std::cout <<std::endl;
    }


    std::cout << std::endl << "TEST EMPTY SQUAD" <<std::endl<<std::endl;

//    try empty squad
    ISquad* empty_squad = new Squad();
    empty_squad->getCount();
    empty_squad->getUnit(10);
    empty_squad->getUnit(0);


    std::cout << std::endl << "TEST CPY SQUAD" <<std::endl<<std::endl;

//    try cpy squad
    ISquad* cpy_squad = new Squad();
    cpy_squad->push(jim);
    cpy_squad->push(dad);
    cpy_squad = squad;
    cpy_squad->getUnit(3)->battleCry();

    std::cout << std::endl << "DELETING SQUAD" <<std::endl<<std::endl;
    delete empty_squad;
    delete squad;
    return 0;
}
