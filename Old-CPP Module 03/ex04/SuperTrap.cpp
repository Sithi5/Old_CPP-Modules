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
    std::cout << "SuperTrap constructor called." << std::endl;

}

SuperTrap::SuperTrap(std::string const &name) 
    : ClapTrap(name), NinjaTrap(name), FragTrap(name)  {
    this->setMaxHitPoints(100);
    this->setHitPoints(100);
    this->setMaxEnergyPoints(120);
    this->setEnergyPoints(120);
    this->setArmorDamageReduction(5);
    this->setMeleeAttack(60);
    this->setRangedAttack(20);
    std::cout << "SuperTrap constructor called." << std::endl;
}

SuperTrap::~SuperTrap() {
    std::cout << "SuperTrap destructor called." << std::endl;
}

SuperTrap    &SuperTrap::operator=(SuperTrap const & rhs) {
    if (this != &rhs) {
        this->_name = rhs.getName();
        this->_hit_points = rhs.getHitPoints();
        this->_max_hit_points = rhs.getMaxHitPoints();
        this->_energy_points = rhs.getEnergyPoints();
        this->_max_energy_points = rhs.getMaxEnergyPoints();
        this->_level = rhs.getLevel();
        this->_melee_attack = rhs.getMeleeAttack();
        this->_ranged_attack = rhs.getRangedAttack();
        this->_armor_damage_reduction = rhs.getArmorDamageReduction();
    }
    return *this;
}

unsigned int SuperTrap::meleeAttack(std::string const &target, std::string const &type)
{
    return (NinjaTrap::meleeAttack(target, type));
}

unsigned int SuperTrap::rangedAttack(std::string const &target, std::string const &type)
{
    return (FragTrap::rangedAttack(target, type));
}