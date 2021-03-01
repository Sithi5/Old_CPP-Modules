#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
    : ClapTrap() {
    this->setMaxHitPoints(60);
    this->setMaxEnergyPoints(120);
    this->setEnergyPoints(120);
    this->setArmorDamageReduction(0);
    this->setMeleeAttack(60);
    this->setRangedAttack(5);
    std::cout << this->getName() << " se réveille dans la décharge et dit : " << "Hahaha, hahaha, je ressuscite." << std::endl;
}

NinjaTrap::NinjaTrap(std::string const &name)
    : ClapTrap(name) {
    this->setMaxHitPoints(60);
    this->setMaxEnergyPoints(120);
    this->setEnergyPoints(120);
    this->setArmorDamageReduction(0);
    this->setMeleeAttack(60);
    this->setRangedAttack(5);
    std::cout << this->getName() << " se réveille dans la décharge et dit : " << "Hahaha, hahaha, je ressuscite." << std::endl;
}


NinjaTrap::~NinjaTrap() {
    std::cout << this->getName() << " meurt et dit : " << "Est-ce que ça veut dire que je peux danser ? Steuplaiiiiiit !" << std::endl;
}

unsigned int NinjaTrap::meleeAttack(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "NINJ4-TP <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "NINJ4-TP <" << this->getName() << "> attaque <" << target << "> au corp a corp, causant <" << this->getMeleeAttack() << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack();
    }
}

unsigned int NinjaTrap::rangedAttack(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "NINJ4-TP <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else {
        std::cout << "NINJ4-TP <" << this->getName() << "> attaque <" << target << "> à distance, causant <"
                  << this->getRangedAttack() << "> points de dégâts !" << std::endl;
        return this->getRangedAttack();
    }
}

void NinjaTrap::ninjaShoeBox(ScavTrap &claptrap){
    std::cout << "NINJ4-TP <" << this->getName() << "> copie " << claptrap.getName() << " et fait un bottle flip Challenge.";
}

void NinjaTrap::ninjaShoeBox(FragTrap &claptrap){
    std::cout << "NINJ4-TP <" << this->getName() << "> copie " << claptrap.getName() << " et fait un Rire diabolique." << std::endl;
}

void NinjaTrap::ninjaShoeBox(NinjaTrap &claptrap){
    std::cout << "NINJ4-TP <" << this->getName() << "> copie " << claptrap.getName() << " et lance un kage bunshin no jutsu." << std::endl;
}

void NinjaTrap::ninjaShoeBox(ClapTrap &claptrap){
    std::cout << "NINJ4-TP <" << this->getName() << "> copie " << claptrap.getName() << " et lance un Yakuza Bunshin no Jutsu." << std::endl;
}