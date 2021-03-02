#include "ScavTrap.hpp"

std::string ScavTrap::_challenges[3] = {
    "Ice Bucket Challenge",
    "Cinnamon Challenge",
    "Bottle Flip Challenge"
};

ScavTrap::ScavTrap(void)
    : ClapTrap() {
    this->setMaxEnergyPoints(50);
    this->setEnergyPoints(50);
    this->setArmorDamageReduction(3);
    this->setMeleeAttack(20);
    this->setRangedAttack(15);
    std::cout << this->getName() << " se réveille dans la décharge et dit : Le meilleur sbire du monde !" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name)
    : ClapTrap(name){
    this->setMaxEnergyPoints(50);
    this->setEnergyPoints(50);
    this->setArmorDamageReduction(3);
    this->setMeleeAttack(20);
    this->setRangedAttack(15);
    std::cout << this->getName() << " se réveille dans la décharge et dit : Le meilleur sbire du monde !" << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << this->getName() << " meurt et dit : On est bien seul par ici..." << std::endl;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const & rhs) {
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

unsigned int ScavTrap::meleeAttack(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "SC4V-TP <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "SC4V-TP <" << this->getName() << "> attaque <" << target << "> au corp a corp, causant <" << this->getMeleeAttack() << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack();
    }
}

unsigned int ScavTrap::rangedAttack(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "SC4V-TP <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else {
        std::cout << "SC4V-TP <" << this->getName() << "> attaque <" << target << "> à distance, causant <"
                  << this->getRangedAttack() << "> points de dégâts !" << std::endl;
        return this->getRangedAttack();
    }
}

void ScavTrap::challengeNewcomer(void) {
    std::cout << "SC4V-TP <" << this->getName() << "> va effectuer le fameux " << ScavTrap::_challenges[rand() % 3] << "."<< std::endl;
}

