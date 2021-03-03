#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

//int main()
//{
//    ISpaceMarine* bob = new TacticalMarine();
//    ISpaceMarine* jim = new AssaultTerminator();
//    ISpaceMarine* dad = new TacticalMarine();
//    ISpaceMarine* mom = new TacticalMarine();
//    ISpaceMarine* nullos = NULL;
//    ISquad* squad = new Squad;
//    squad->push(bob);
//
//    //    already in squad bob
//    squad->push(bob);
//
//
//    squad->push(jim);
//
////    pushing null spacemarine
//    squad->push(nullos);
//
//    //    already in squad jim
//    squad->push(jim);
//
//    squad->push(dad);
//    squad->push(mom);
//
//    std::cout << std::endl << "PRINTING ALL UNITS AND ATTACKS OF THE SQUAD" <<std::endl<<std::endl;
//
//    for (int i = 0; i < squad->getCount(); i++)
//    {
//        std::cout << "Getting unit number : "<< i <<std::endl<<std::endl;
//        ISpaceMarine* cur = squad->getUnit(i);
//        cur->battleCry();
//        cur->rangedAttack();
//        cur->meleeAttack();
//        std::cout <<std::endl;
//    }
//
//    std::cout << std::endl << "TEST EMPTY SQUAD" <<std::endl<<std::endl;
//
////    try empty squad
//    ISquad* empty_squad = new Squad();
//    empty_squad->getCount();
//    empty_squad->getUnit(10);
//    empty_squad->getUnit(0);
//
//    std::cout << std::endl << "TEST CPY SQUAD" <<std::endl<<std::endl;
//
//    ISpaceMarine* deam = new TacticalMarine();
//    ISpaceMarine* dame = new AssaultTerminator();
//    ISpaceMarine* door = new AssaultTerminator();
//
////    try cpy squad
//    Squad to_cpy;
//    to_cpy.push(dame);
//    Squad* cpied = new Squad(to_cpy);
//    cpied->push(deam);
//    cpied->push(door);
//
//    std::cout << std::endl << "TEST EQ OPERATOR" <<std::endl<<std::endl;
//
//    //    try eq operator
//
//    Squad* cpy_squad = new Squad();
//    cpy_squad->push(bob->clone());
//    cpy_squad->getUnit(0)->battleCry();
//    *cpy_squad = *cpied;
//    cpy_squad->getUnit(0)->battleCry();
//
//    std::cout << std::endl << "DELETING SQUAD" <<std::endl<<std::endl;
//    delete empty_squad;
//    delete squad;
//    delete cpied;
//    delete cpy_squad;
//    return 0;
//}

int main(){
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISquad* vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete vlc;
    return 0;
}
