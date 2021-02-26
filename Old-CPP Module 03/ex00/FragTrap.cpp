//
// Created by MaSit on 26/02/2021.
//

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
    :_hit_points(100), _max_hit_points(100),_energy_points(100),_level(1), _name(name),_melee_attack(30),
    _ranged_attack(20),_armor_damage_reduction(5) {
    srand (time(NULL));
    std::cout << this->getName() << " se réveille dans la décharge et dit : " << "Hahaha, hahaha, je ressuscite." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << this->getName() << " meurt et dit : " << "Est-ce que ça veut dire que je peux danser ? Steuplaiiiiiit !" << std::endl;
}

unsigned int FragTrap::getHitPoints() const {
    return _hit_points;
}

void FragTrap::setHitPoints(unsigned int hitPoints) {
    if (hitPoints > this->getMaxHitPoints()){
        _hit_points = this->getMaxHitPoints();
    }
    else{
        _hit_points = hitPoints;
    }
    if (_hit_points == 0){
        std::cout << "FR4G-TP <" << this->_name << "> est hors-service..." << std::endl;
    }
}

unsigned int FragTrap::getMaxHitPoints() const {
    return _max_hit_points;
}

void FragTrap::setMaxHitPoints(unsigned int maxHitPoints) {
    _max_hit_points = maxHitPoints;
}

unsigned int FragTrap::getMaxEnergyPoints() const {
    return _max_energy_points;
}

void FragTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints) {
    _max_energy_points = maxEnergyPoints;
}

unsigned int FragTrap::getEnergyPoints() const {
    return _energy_points;
}

void FragTrap::setEnergyPoints(unsigned int energyPoints) {
    if (energyPoints > this->getMaxEnergyPoints()){
        _energy_points = this->getMaxEnergyPoints();
    }
    else{
        _energy_points = energyPoints;
    }
}

unsigned int FragTrap::getLevel() const {
    return _level;
}

void FragTrap::setLevel(unsigned int level) {
    _level = level;
}

const std::string &FragTrap::getName() const {
    return _name;
}

void FragTrap::setName(const std::string &name) {
    _name = name;
}

unsigned int FragTrap::getMeleeAttack() const {
    return _melee_attack;
}

void FragTrap::setMeleeAttack(unsigned int meleeAttack) {
    _melee_attack = meleeAttack;
}

unsigned int FragTrap::getRangedAttack() const {
    return _ranged_attack;
}

void FragTrap::setRangedAttack(unsigned int rangedAttack) {
    _ranged_attack = rangedAttack;
}

unsigned int FragTrap::getArmorDamageReduction() const {
    return _armor_damage_reduction;
}

void FragTrap::setArmorDamageReduction(unsigned int armorDamageReduction) {
    _armor_damage_reduction = armorDamageReduction;
}

unsigned int FragTrap::meleeAttack(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> " << "est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> " << "attaque <" << target << "> " << "au corp a corp, causant <" << this->getMeleeAttack() << "> " << "points de dégâts !" << std::endl;
        return this->getMeleeAttack();
    }
}

unsigned int FragTrap::echappementCryogénique(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> " << "est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> " << "attaque <" << target << "> " << "avec Échappement cryogénique, causant <" << this->getMeleeAttack() * 1.5 << "> " << "points de dégâts !" << std::endl;
        return this->getMeleeAttack() * 1.5;
    }
}

unsigned int FragTrap::rireDiabolique(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> " << "est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> " << "attaque <" << target << "> " << "avec Rire diabolique (Mouhahahahaha), causant <" << this->getMeleeAttack() * 0 << "> " << "points de dégâts !" << std::endl;
        return this->getMeleeAttack() * 0;
    }
}

unsigned int FragTrap::grenadeDeLaColere(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> " << "est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> " << "attaque <" << target << "> " << "avec Grenade de la colère, causant <" << this->getRangedAttack() * 2 << "> " << "points de dégâts !" << std::endl;
        return this->getRangedAttack() * 2;
    }
}

unsigned int FragTrap::machineDeMort(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> " << "est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> " << "attaque <" << target << "> " << "avec Machine de mort, causant <" << this->getMeleeAttack() * 2 << "> " << "points de dégâts !" << std::endl;
        return this->getMeleeAttack() * 2;
    }
}

unsigned int FragTrap::punchDHyperion(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> " << "est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> " << "attaque <" << target << "> " << "avec Punch d'Hyperion, causant <" << this->getRangedAttack() * 1.5 << "> " << "points de dégâts !" << std::endl;
        return this->getRangedAttack() * 1.5;
    }
}

unsigned int FragTrap::rangedAttack(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> " << "est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else {
        std::cout << "FR4G-TP <" << this->_name << "> " << "attaque <" << target << "> " << "à distance, causant <"
                  << this->getRangedAttack() << "> " << "points de dégâts !" << std::endl;
        return this->getRangedAttack();
    }
}

void FragTrap::takeDamage(unsigned int amount) {
    if (amount < this->getArmorDamageReduction()){
        std::cout << "FR4G-TP <" << this->_name << "> " << "se fait frapper mais ce n'est pas très efficace..." << std::endl;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> " << "se fait frapper et reçoit <" << amount << "> point de dégats. Après réduction de l'armure, il pert : <" <<amount - this->getArmorDamageReduction() << "> " << "points de vie !" << std::endl;
        if (this->getHitPoints() - (amount - this->getArmorDamageReduction()) > 0){
            this->setHitPoints(this->getHitPoints() - (amount - this->getArmorDamageReduction()));
        }
        else{
            this->setHitPoints(0);
        }
    }

}

void FragTrap::beRepaired(unsigned int amount) {
    this->setHitPoints(this->getHitPoints() + amount);
    std::cout << "FR4G-TP <" << this->_name << "> " << "se répare! Il a maintenant : <" <<this->getHitPoints() << "> " << "points de vie !" << std::endl;
}

void FragTrap::chargingBattery(unsigned int amount) {
    this->setEnergyPoints(this->getEnergyPoints() + amount);
    std::cout << "FR4G-TP <" << this->_name << "> " << "se recharge! Il a maintenant : <" <<this->getEnergyPoints() << "> " << "points d'energie !" << std::endl;
}

unsigned int FragTrap::vaulthunter_dot_exe(const std::string &target) {
    if (this->getEnergyPoints() < 25){
        std::cout << "FR4G-TP <" << this->_name << "> " << "n'a plus d'energie..." << std::endl;
        return 0;
    }
    else{
        std::cout << "energie ici est = " << this->getEnergyPoints() <<std::endl;
        std::cout << "energie ici est = " << this->getEnergyPoints() - 25 <<std::endl;

        this->setEnergyPoints(this->getEnergyPoints() - 25);
        unsigned int (FragTrap::*p[5])(const std::string &target) const = {
                &FragTrap::machineDeMort,
                &FragTrap::rireDiabolique,
                &FragTrap::echappementCryogénique,
                &FragTrap::punchDHyperion,
                &FragTrap::grenadeDeLaColere,
        };
        std::string key[5] = {
                "machineDeMort",
                "rireDiabolique",
                "echappementCryogénique",
                "punchDHyperion",
                "grenadeDeLaColere",
        };
        std::string random_attack = key[rand() % 5];
        int key_size = sizeof(key) / sizeof(*key);

        for(int i = 0; i < key_size; i++){
            if (!key[i].compare(random_attack)){
                return (this->*p[i])(target);
            }
        }
        return 0;
    }


}
