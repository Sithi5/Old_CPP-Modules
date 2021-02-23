#include "Zombie.hpp"
#include "ZombieEvent.hpp"


int     main(void){
    ZombieEvent event = ZombieEvent();

    std::cout << "Creating first zombie with ZombieEvent : " << std::endl;
    Zombie *zombie1 = event.randomChump();

    std::cout << std::endl <<"Changing type of first zombie : " << std::endl;
    std::cout << "type of zombie1 : " << zombie1->getType() << std::endl;
    zombie1->setType("pop dancer");
    std::cout << "type of zombie1 : " << zombie1->getType() << std::endl;


    std::cout << std::endl << "Changing ZombieEvent type to 'brain eater' and creating zombie2 : " <<std::endl;
    event.setZombieType("brain eater");
    Zombie *zombie2 = event.randomChump();

    std::cout << std::endl << "Changing name of second zombie : " << std::endl;
    zombie2->getName();
    std::cout << "name of zombie2 : " << zombie2->getName() << std::endl;
    zombie2->setName("Bob");
    std::cout << "name of zombie2 : " << zombie2->getName() << std::endl;

    std::cout << std::endl << "Changing type of second zombie : " << std::endl;
    std::cout << "type of zombie2 : " << zombie2->getType() << std::endl;
    zombie2->setType("Biggass zombie");
    std::cout << "type of zombie2 : " << zombie2->getType() << std::endl;

    Zombie *zombie3 = event.randomChump();
    std::cout << std::endl << "Changing name and type of third zombie : " << std::endl;
    std::cout << "name of zombie3 : " << zombie3->getName() << std::endl;
    zombie3->setName("Billy");
    std::cout << "name of zombie3 : " << zombie3->getName() << std::endl;
    std::cout << "type of zombie3 : " << zombie3->getType() << std::endl;
    zombie3->setType("the kid");
    std::cout << "type of zombie3 : " << zombie3->getType() << std::endl;

    std::cout << std::endl << "Advert all zombies : " << std::endl;
    zombie1->advert();
    zombie2->advert();
    zombie3->advert();

    delete zombie1;
    delete zombie2;
    delete zombie3;
}