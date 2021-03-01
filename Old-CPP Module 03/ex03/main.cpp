#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    srand(time(NULL));
    int random_num;

    FragTrap mathieu = FragTrap("Mathieu");
    ScavTrap maboubouce = ScavTrap("Maboubouce");

    std::cout
            << "Bienvenue dans l'arene peuple de la cité impérial ! Pour ce match, nous avons de la chair fraiche, deux nouveaux chiens ! Alors ne perdons pas de temps ! Que la bataille... commence !"
            << std::endl;
    std::cout << std::endl;

    std::cout << mathieu.getName() << " a " << mathieu.getHitPoints() << " point de vie." << std::endl;
    std::cout << mathieu.getName() << " a " << mathieu.getEnergyPoints() << " point d'energie." << std::endl;

    std::cout << maboubouce.getName() << " a " << maboubouce.getHitPoints() << " point de vie." << std::endl;
    std::cout << maboubouce.getName() << " a " << maboubouce.getEnergyPoints() << " point d'energie." << std::endl;

    while (mathieu.getHitPoints() > 0 and maboubouce.getHitPoints() > (unsigned int) 0) {
        std::cout << mathieu.getName() << " a " << mathieu.getHitPoints() << " point de vie." << std::endl;
        std::cout << mathieu.getName() << " a " << mathieu.getEnergyPoints() << " point d'energie." << std::endl;

        std::cout << maboubouce.getName() << " a " << maboubouce.getHitPoints() << " point de vie." << std::endl;
        std::cout << maboubouce.getName() << " a " << maboubouce.getEnergyPoints() << " point d'energie." << std::endl;

        random_num = rand() % 6;
        if (random_num < 4) {
            maboubouce.takeDamage(mathieu.vaulthunter_dot_exe("Maboubouce"));
            if (maboubouce.getHitPoints() <= 0) {
                break;
            }
        } else if (random_num == 4) {
            mathieu.beRepaired((unsigned int) rand() % 40 + 15);
        } else {
            mathieu.chargingBattery((unsigned int) rand() % 40 + 15);
        }

        random_num = rand() % 7;

        if (random_num < 4) {
            if (random_num % 2 == 0)
                mathieu.takeDamage(maboubouce.rangedAttack("Mathieu"));
            else
                mathieu.takeDamage(maboubouce.meleeAttack("Mathieu"));
            if (mathieu.getHitPoints() <= 0) {
                break;
            }
        } else if (random_num == 4) {
            maboubouce.beRepaired((unsigned int) rand() % 40 + 15);
        } else if (random_num == 5) {
            maboubouce.chargingBattery((unsigned int) rand() % 40 + 15);
        } else
            maboubouce.challengeNewcomer();

        std::cout << std::endl;
    }
    if (mathieu.getHitPoints() > (unsigned int) 0) {
        std::cout << "Bonnes gens, nous avons un vainqueur ! Que tout le monde salue le combattant **"
                  << mathieu.getName()
                  << "** ! Vainqueur, quittez l'arène et allez vous reposez ! Vous l'avez bien mérité !" << std::endl;
    } else {
        std::cout << "Bonnes gens, nous avons un vainqueur ! Que tout le monde salue le combattant **"
                  << maboubouce.getName()
                  << "** ! Vainqueur, quittez l'arène et allez vous reposez ! Vous l'avez bien mérité !" << std::endl;
    }
    std::cout << std::endl;
    return 0;
}