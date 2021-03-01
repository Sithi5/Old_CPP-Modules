#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
    : ClapTrap(), NinjaTrap(), FragTrap() {
    this->setMaxHitPoints(100);
    this->setHitPoints(100);
    this->setMaxEnergyPoints(120);
    this->setEnergyPoints(120);
    this->setArmorDamageReduction(5);
    this->setMeleeAttack(60);
    this->setRangedAttack(20);
}

SuperTrap::SuperTrap(std::string const &name) 
    : ClapTrap(name), NinjaTrap(), FragTrap()  {
    this->setMaxHitPoints(100);
    this->setHitPoints(100);
    this->setMaxEnergyPoints(120);
    this->setEnergyPoints(120);
    this->setArmorDamageReduction(5);
    this->setMeleeAttack(60);
    this->setRangedAttack(20);
}

SuperTrap::~SuperTrap() {}

unsigned int SuperTrap::meleeAttack(std::string const &target, std::string const &type)
{
    return (NinjaTrap::meleeAttack(target, type));
}

unsigned int SuperTrap::rangedAttack(std::string const &target, std::string const &type)
{
    return (FragTrap::rangedAttack(target, type));
}