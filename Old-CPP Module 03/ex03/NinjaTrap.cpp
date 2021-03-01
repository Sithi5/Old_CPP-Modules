#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
    : ClapTrap() {
    this->setMaxEnergyPoints(100);
    this->setEnergyPoints(100);
    this->setArmorDamageReduction(5);
    this->setMeleeAttack(30);
    this->setRangedAttack(20);
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

void NinjaTrap::ninjaShoeBox(ScavTrap &claptrap){
    std::cout << "<" << this->getName() << "> copie " << claptrap.getName() << " et fait un bottle flip Challenge.";
}

void NinjaTrap::ninjaShoeBox(FragTrap &claptrap){
    std::cout << "<" << this->getName() << "> copie " << claptrap.getName() << " et fait un Rire diabolique." << std::endl;
}

void NinjaTrap::ninjaShoeBox(NinjaTrap &claptrap){
    std::cout << "<" << this->getName() << "> copie " << claptrap.getName() << " et lance un kage bunshin no jutsu." << std::endl;
}

void NinjaTrap::ninjaShoeBox(ClapTrap &claptrap){
    std::cout << "<" << this->getName() << "> copie " << claptrap.getName() << " et lance un Yakuza Bunshin no Jutsu." << std::endl;
}