#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) 
    :  {
    this->setHitPoints(FragTrap::getHitPoints());
    this->setMaxHitPoints(FragTrap::getHitPoints());
    this->setMaxEnergyPoints(NinjaTrap::getHitPoints());
    this->setEnergyPoints(NinjaTrap::getHitPoints());
    this->setArmorDamageReduction(FragTrap::getHitPoints());
    this->setMeleeAttack(NinjaTrap::getHitPoints());
    this->setRangedAttack(FragTrap::getHitPoints());
    std::cout << this->getName() << " se réveille dans la décharge et dit : " << "Hahaha, hahaha, je ressuscite." << std::endl;
}

SuperTrap::SuperTrap(std::string const &name) 
    : FragTrap(name), NinjaTrap(name) {
    this->setHitPoints(FragTrap::getHitPoints());
    this->setMaxHitPoints(FragTrap::getHitPoints());
    this->setMaxEnergyPoints(NinjaTrap::getHitPoints());
    this->setEnergyPoints(NinjaTrap::getHitPoints());
    this->setArmorDamageReduction(FragTrap::getHitPoints());
    this->setMeleeAttack(NinjaTrap::getHitPoints());
    this->setRangedAttack(FragTrap::getHitPoints());
    std::cout << this->getName() << " se réveille dans la décharge et dit : " << "Hahaha, hahaha, je ressuscite." << std::endl;
}


SuperTrap::~SuperTrap() {
    std::cout << this->getName() << " meurt et dit : " << "Est-ce que ça veut dire que je peux danser ? Steuplaiiiiiit !" << std::endl;
}

unsigned int SuperTrap::meleeAttack(const std::string &target) const {
    NinjaTrap::meleeAttack(target);
}

unsigned int SuperTrap::rangedAttack(const std::string &target) const {
    FragTrap::rangedAttack(target);
}
