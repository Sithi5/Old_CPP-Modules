#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) 
    :  FragTrap(), NinjaTrap() {
    this->setHitPoints(FragTrap::getHitPoints());
    this->setMaxHitPoints(FragTrap::getMaxHitPoints());
    this->setMaxEnergyPoints(NinjaTrap::getMaxEnergyPoints());
    this->setEnergyPoints(NinjaTrap::getEnergyPoints());
    this->setArmorDamageReduction(FragTrap::getArmorDamageReduction());
    this->setMeleeAttack(NinjaTrap::getMeleeAttack());
    this->setRangedAttack(FragTrap::getRangedAttack());
    std::cout << this->getName() << " se réveille dans la décharge et dit : " << "Hahaha, hahaha, je ressuscite." << std::endl;
}

SuperTrap::SuperTrap(std::string const &name) 
    : FragTrap(name), NinjaTrap(name) {
    this->setHitPoints(FragTrap::getHitPoints());
    this->setMaxHitPoints(FragTrap::getMaxHitPoints());
    this->setMaxEnergyPoints(NinjaTrap::getMaxEnergyPoints());
    this->setEnergyPoints(NinjaTrap::getEnergyPoints());
    this->setArmorDamageReduction(FragTrap::getArmorDamageReduction());
    this->setMeleeAttack(NinjaTrap::getMeleeAttack());
    this->setRangedAttack(FragTrap::getRangedAttack());
    std::cout << this->getName() << " se réveille dans la décharge et dit : " << "Hahaha, hahaha, je ressuscite." << std::endl;
}

SuperTrap::~SuperTrap() {
    std::cout << this->getName() << " meurt et dit : " << "Est-ce que ça veut dire que je peux danser ? Steuplaiiiiiit !" << std::endl;
}
