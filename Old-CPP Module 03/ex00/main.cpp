#include <iostream>
#include "FragTrap.hpp"

int main(void) {
    FragTrap mathieu = FragTrap("Mathieu");
    FragTrap jududu = FragTrap("Jududu");

    jududu.takeDamage(mathieu.meleeAttack("Jududu"));
    mathieu.takeDamage(jududu.meleeAttack("Mathieu"));
    mathieu.takeDamage(jududu.rangedAttack("Mathieu"));
    jududu.takeDamage(mathieu.rangedAttack("Jududu"));
    std::cout << mathieu.getName() << " a " << mathieu.getHitPoints() << " point de vie." << std::endl;
    std::cout << jududu.getName() << " a " << jududu.getHitPoints() << " point de vie." << std::endl;

    mathieu.beRepaired(50);
    mathieu.beRepaired(1500);
    jududu.beRepaired(1500);



    while(mathieu.getHitPoints() > 0 and jududu.getHitPoints() > 0){
        std::cout << mathieu.getName() << " a " << mathieu.getHitPoints() << " point de vie." << std::endl;
        std::cout << mathieu.getName() << " a " << mathieu.getEnergyPoints() << " point d'energie." << std::endl;

        std::cout << jududu.getName() << " a " << jududu.getHitPoints() << " point de vie." << std::endl;
        std::cout << jududu.getName() << " a " << jududu.getEnergyPoints() << " point d'energie." << std::endl;

        if (mathieu.getEnergyPoints() >= 25){
            jududu.takeDamage(mathieu.vaulthunter_dot_exe("Jududu"));
        }
        else{
            mathieu.chargingBattery(rand() % 100 + 15);
        }
        if (jududu.getEnergyPoints() >= 25) {
            mathieu.takeDamage(jududu.vaulthunter_dot_exe("Mathieu"));
        }
        else{
            jududu.chargingBattery(rand() % 100 + 15);
        }
    }
    if (mathieu.getHitPoints() > 0){
        std::cout << "Bonnes gens, nous avons un vainqueur ! Que tout le monde salue le combattant " << mathieu.getName() << " ! Vainqueur, quittez l'arène et allez vous reposez ! Vous l'avez bien mérité !" << std::endl;
    }
    else{
        std::cout << "Bonnes gens, nous avons un vainqueur ! Que tout le monde salue le combattant " << jududu.getName() << " ! Vainqueur, quittez l'arène et allez vous reposez ! Vous l'avez bien mérité !" << std::endl;
    }

    return 0;
}