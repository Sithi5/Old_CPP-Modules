#include <iostream>
#include "FragTrap.hpp"

int main(void) {
    srand (time(NULL));
    int random_num;

    FragTrap mathieu = FragTrap("Mathieu");
    FragTrap jududu = FragTrap("Jududu");

    std::cout << "Bienvenue dans l'arene peuple de la cité impérial ! Pour ce match, nous avons de la chair fraiche, deux nouveaux chiens ! Alors ne perdons pas de temps ! Que la bataille... commence !" << std::endl;
    std::cout << std::endl;

    while(mathieu.getHitPoints() > 0 and jududu.getHitPoints() > (unsigned int)0){
        std::cout << mathieu.getName() << " a " << mathieu.getHitPoints() << " point de vie." << std::endl;
        std::cout << mathieu.getName() << " a " << mathieu.getEnergyPoints() << " point d'energie." << std::endl;

        std::cout << jududu.getName() << " a " << jududu.getHitPoints() << " point de vie." << std::endl;
        std::cout << jududu.getName() << " a " << jududu.getEnergyPoints() << " point d'energie." << std::endl;

        random_num = rand() %6;
        if (random_num < 4){
            jududu.takeDamage(mathieu.vaulthunter_dot_exe("Jududu"));
            if (jududu.getHitPoints() <= 0){
                break ;
            }
        }
        else if (random_num == 4){
            mathieu.beRepaired((unsigned int)rand() % 40 + 15);
        }
        else{
            mathieu.chargingBattery((unsigned int)rand() % 40 + 15);
        }

        random_num = rand() %6;

        if (random_num < 4){
            mathieu.takeDamage(jududu.vaulthunter_dot_exe("Mathieu"));
            if (mathieu.getHitPoints() <= 0){
                break ;
            }
        }
        else if (random_num == 4){
            jududu.beRepaired((unsigned int)rand() % 40 + 15);
        }
        else{
            jududu.chargingBattery((unsigned int)rand() % 40 + 15);
        }

        std::cout << std::endl;
    }
    if (mathieu.getHitPoints() > (unsigned int)0){
        std::cout << "Bonnes gens, nous avons un vainqueur ! Que tout le monde salue le combattant **" << mathieu.getName() << "** ! Vainqueur, quittez l'arène et allez vous reposez ! Vous l'avez bien mérité !" << std::endl;
    }
    else{
        std::cout << "Bonnes gens, nous avons un vainqueur ! Que tout le monde salue le combattant **" << jududu.getName() << "** ! Vainqueur, quittez l'arène et allez vous reposez ! Vous l'avez bien mérité !" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}