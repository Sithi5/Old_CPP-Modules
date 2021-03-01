#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : _hit_points((unsigned int)100), _max_hit_points((unsigned int)100),_energy_points((unsigned int)0), _max_energy_points((unsigned int)0),
      _level((unsigned int)1), _name("default"),_melee_attack((unsigned int)0), _ranged_attack((unsigned int)0), _armor_damage_reduction((unsigned int)0){
    srand (time(NULL));
    std::cout << "Void Parent constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
    : _hit_points((unsigned int)100), _max_hit_points((unsigned int)100),_energy_points((unsigned int)0), _max_energy_points((unsigned int)0),
    _level((unsigned int)1), _name(name),_melee_attack((unsigned int)0), _ranged_attack((unsigned int)0), _armor_damage_reduction((unsigned int)0) {
    srand (time(NULL));
    std::cout << "Parent constructor called." << std::endl;
}

ClapTrap::ClapTrap (ClapTrap const &src) {
    *this = src;
    return ;
}

ClapTrap::~ClapTrap() {
    std::cout << "Parent destructor called." << std::endl;
}

ClapTrap    &ClapTrap::operator=(ClapTrap const & rhs) {
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

unsigned int ClapTrap::getHitPoints() const {
    return this->_hit_points;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
    if (hitPoints > this->getMaxHitPoints()){
        this->_hit_points = this->getMaxHitPoints();
    }
    else{
        this->_hit_points = hitPoints;
    }
    if (this->_hit_points == (unsigned int)0){
        std::cout << "<" << this->getName() << "> est hors-service..." << std::endl;
    }
}

unsigned int ClapTrap::getMaxHitPoints() const {
    return this->_max_hit_points;
}

void ClapTrap::setMaxHitPoints(unsigned int maxHitPoints) {
    this->_max_hit_points = maxHitPoints;
}

unsigned int ClapTrap::getMaxEnergyPoints() const {
    return this->_max_energy_points;
}

void ClapTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints) {
    this->_max_energy_points = maxEnergyPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return this->_energy_points;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    if (energyPoints > this->getMaxEnergyPoints()){
        this->_energy_points = this->getMaxEnergyPoints();
    }
    else{
        this->_energy_points = energyPoints;
    }
}

unsigned int ClapTrap::getLevel() const {
    return this->_level;
}

void ClapTrap::setLevel(unsigned int level) {
    this->_level = level;
}

const std::string &ClapTrap::getName() const {
    return this->_name;
}

void ClapTrap::setName(const std::string &name) {
    this->_name = name;
}

unsigned int ClapTrap::getMeleeAttack() const {
    return this->_melee_attack;
}

void ClapTrap::setMeleeAttack(unsigned int meleeAttack) {
    this->_melee_attack = meleeAttack;
}

unsigned int ClapTrap::getRangedAttack() const {
    return this->_ranged_attack;
}

void ClapTrap::setRangedAttack(unsigned int rangedAttack) {
    this->_ranged_attack = rangedAttack;
}

unsigned int ClapTrap::getArmorDamageReduction() const {
    return this->_armor_damage_reduction;
}

void ClapTrap::setArmorDamageReduction(unsigned int armorDamageReduction) {
    this->_armor_damage_reduction = armorDamageReduction;
}



void ClapTrap::takeDamage(unsigned int amount) {
    if (amount < this->getArmorDamageReduction()){
        std::cout << "<" << this->getName() << "> se fait frapper mais ce n'est pas très efficace..." << std::endl;
    }
    else{
        std::cout << "<" << this->getName() << "> se fait frapper et reçoit <" << amount << "> point de dégats. Après réduction de l'armure, il pert : <" <<amount - this->getArmorDamageReduction() << "> points de vie !" << std::endl;
        if (this->getHitPoints() > (amount - this->getArmorDamageReduction())){
            this->setHitPoints(this->getHitPoints() - (amount - this->getArmorDamageReduction()));
        }
        else{
            this->setHitPoints((unsigned int)0);
        }
    }

}

void ClapTrap::beRepaired(unsigned int amount) {
    this->setHitPoints(this->getHitPoints() + amount);
    std::cout << "<" << this->getName() << "> se répare! Il a maintenant : <" <<this->getHitPoints() << "> points de vie !" << std::endl;
}

void ClapTrap::chargingBattery(unsigned int amount) {
    this->setEnergyPoints(this->getEnergyPoints() + amount);
    std::cout << "<" << this->getName() << "> se recharge! Il a maintenant : <" <<this->getEnergyPoints() << "> points d'energie !" << std::endl;
}

