#include "ScavTrap.hpp"

std::string ScavTrap::_challenges[3] = {
    "Ice Bucket Challenge",
    "Cinnamon Challenge",
    "Bottle Flip Challenge"
};

ScavTrap::ScavTrap(void)
    : _hit_points((unsigned int)100), _max_hit_points((unsigned int)100),_energy_points((unsigned int)50), _max_energy_points((unsigned int)50),
    _level((unsigned int)1), _name("default"), _melee_attack((unsigned int)30), _ranged_attack((unsigned int)15), _armor_damage_reduction((unsigned int)3) {
    srand (time(NULL));
    std::cout << this->getName() << " se réveille dans la décharge et dit : Le meilleur sbire du monde !" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name)
    : _hit_points((unsigned int)100), _max_hit_points((unsigned int)100),_energy_points((unsigned int)50), _max_energy_points((unsigned int)50),
    _level((unsigned int)1), _name(name),_melee_attack((unsigned int)30), _ranged_attack((unsigned int)20), _armor_damage_reduction((unsigned int)5) {
    srand (time(NULL));
    std::cout << this->getName() << " se réveille dans la décharge et dit : Le meilleur sbire du monde !" << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const &src) {
    *this = src;
    return ;
}

ScavTrap::~ScavTrap() {
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

unsigned int ScavTrap::getHitPoints() const {
    return this->_hit_points;
}

void ScavTrap::setHitPoints(unsigned int hitPoints) {
    if (hitPoints > this->getMaxHitPoints()){
        this->_hit_points = this->getMaxHitPoints();
    }
    else{
        this->_hit_points = hitPoints;
    }
    if (this->_hit_points == (unsigned int)0){
        std::cout << "SC4V-TP <" << this->_name << "> est hors-service..." << std::endl;
    }
}

unsigned int ScavTrap::getMaxHitPoints() const {
    return this->_max_hit_points;
}

void ScavTrap::setMaxHitPoints(unsigned int maxHitPoints) {
    this->_max_hit_points = maxHitPoints;
}

unsigned int ScavTrap::getMaxEnergyPoints() const {
    return this->_max_energy_points;
}

void ScavTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints) {
    this->_max_energy_points = maxEnergyPoints;
}

unsigned int ScavTrap::getEnergyPoints() const {
    return this->_energy_points;
}

void ScavTrap::setEnergyPoints(unsigned int energyPoints) {
    if (energyPoints > this->getMaxEnergyPoints()){
        this->_energy_points = this->getMaxEnergyPoints();
    }
    else{
        this->_energy_points = energyPoints;
    }
}

unsigned int ScavTrap::getLevel() const {
    return this->_level;
}

void ScavTrap::setLevel(unsigned int level) {
    this->_level = level;
}

const std::string &ScavTrap::getName() const {
    return this->_name;
}

void ScavTrap::setName(const std::string &name) {
    this->_name = name;
}

unsigned int ScavTrap::getMeleeAttack() const {
    return this->_melee_attack;
}

void ScavTrap::setMeleeAttack(unsigned int meleeAttack) {
    this->_melee_attack = meleeAttack;
}

unsigned int ScavTrap::getRangedAttack() const {
    return this->_ranged_attack;
}

void ScavTrap::setRangedAttack(unsigned int rangedAttack) {
    this->_ranged_attack = rangedAttack;
}

unsigned int ScavTrap::getArmorDamageReduction() const {
    return this->_armor_damage_reduction;
}

void ScavTrap::setArmorDamageReduction(unsigned int armorDamageReduction) {
    this->_armor_damage_reduction = armorDamageReduction;
}

unsigned int ScavTrap::meleeAttack(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "SC4V-TP <" << this->_name << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "SC4V-TP <" << this->_name << "> attaque <" << target << "> au corp a corp, causant <" << this->getMeleeAttack() << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack();
    }
}

unsigned int ScavTrap::rangedAttack(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "SC4V-TP <" << this->_name << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else {
        std::cout << "SC4V-TP <" << this->_name << "> attaque <" << target << "> à distance, causant <"
                  << this->getRangedAttack() << "> points de dégâts !" << std::endl;
        return this->getRangedAttack();
    }
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (amount < this->getArmorDamageReduction()){
        std::cout << "SC4V-TP <" << this->_name << "> se fait frapper mais ce n'est pas très efficace..." << std::endl;
    }
    else{
        std::cout << "SC4V-TP <" << this->_name << "> se fait frapper et reçoit <" << amount << "> point de dégats. Après réduction de l'armure, il pert : <" <<amount - this->getArmorDamageReduction() << "> points de vie !" << std::endl;
        if (this->getHitPoints() > (amount - this->getArmorDamageReduction())){
            this->setHitPoints(this->getHitPoints() - (amount - this->getArmorDamageReduction()));
        }
        else{
            this->setHitPoints((unsigned int)0);
        }
    }

}

void ScavTrap::beRepaired(unsigned int amount) {
    this->setHitPoints(this->getHitPoints() + amount);
    std::cout << "SC4V-TP <" << this->_name << "> se répare! Il a maintenant : <" <<this->getHitPoints() << "> points de vie !" << std::endl;
}

void ScavTrap::chargingBattery(unsigned int amount) {
    this->setEnergyPoints(this->getEnergyPoints() + amount);
    std::cout << "SC4V-TP <" << this->_name << "> se recharge! Il a maintenant : <" <<this->getEnergyPoints() << "> points d'energie !" << std::endl;
}

void ScavTrap::challengeNewcomer(void) {
    std::cout << "SC4V-TP <" << this->_name << "> va effectuer le fameux " << ScavTrap::_challenges[rand() % 3] << std::endl;
}

