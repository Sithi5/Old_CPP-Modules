#include <iostream>
#include "FragTrap.hpp"

int main(void) {
    srand (time(NULL));

    FragTrap mathieu = FragTrap("Mathieu");
    FragTrap jududu = FragTrap("Jududu");

    jududu.takeDamage(mathieu.meleeAttack("Jududu"));
    mathieu.takeDamage(jududu.meleeAttack("Mathieu"));
    mathieu.takeDamage(jududu.rangedAttack("Mathieu"));
    jududu.takeDamage(mathieu.rangedAttack("Jududu"));
    std::cout << mathieu.getName() << " a " << mathieu.getHitPoints() << " point de vie." << std::endl;
    std::cout << jududu.getName() << " a " << jududu.getHitPoints() << " point de vie." << std::endl;

    mathieu.beRepaired((unsigned int)50);
    mathieu.beRepaired((unsigned int)1500);
    jududu.beRepaired((unsigned int)1500);

    while(mathieu.getHitPoints() > 0 and jududu.getHitPoints() > (unsigned int)0){
        std::cout << mathieu.getName() << " a " << mathieu.getHitPoints() << " point de vie." << std::endl;
        std::cout << mathieu.getName() << " a " << mathieu.getEnergyPoints() << " point d'energie." << std::endl;

        std::cout << jududu.getName() << " a " << jududu.getHitPoints() << " point de vie." << std::endl;
        std::cout << jududu.getName() << " a " << jududu.getEnergyPoints() << " point d'energie." << std::endl;

        if (mathieu.getEnergyPoints() >= (unsigned int)25){
            jududu.takeDamage(mathieu.vaulthunter_dot_exe("Jududu"));

        }
        else{
            mathieu.chargingBattery((unsigned int)rand() % 100 + 15);
        }
        if (jududu.getEnergyPoints() >= (unsigned int)25) {
            mathieu.takeDamage(jududu.vaulthunter_dot_exe("Mathieu"));

        }
        else{
            jududu.chargingBattery((unsigned int)rand() % 100 + 15);
        }
        std::cout << std::endl;
    }
    if (mathieu.getHitPoints() > (unsigned int)0){
        std::cout << "Bonnes gens, nous avons un vainqueur ! Que tout le monde salue le combattant " << mathieu.getName() << " ! Vainqueur, quittez l'arène et allez vous reposez ! Vous l'avez bien mérité !" << std::endl;
    }
    else{
        std::cout << "Bonnes gens, nous avons un vainqueur ! Que tout le monde salue le combattant " << jududu.getName() << " ! Vainqueur, quittez l'arène et allez vous reposez ! Vous l'avez bien mérité !" << std::endl;
    }
    return 0;
}