#include "FragTrap.hpp"

NinjaTrap::NinjaTrap(void)
    : _hit_points((unsigned int)100), _max_hit_points((unsigned int)100),_energy_points((unsigned int)100), _max_energy_points((unsigned int)100),
    _level((unsigned int)1), _name("default"),_melee_attack((unsigned int)30), _ranged_attack((unsigned int)20),_armor_damage_reduction((unsigned int)5) {
    srand (time(NULL));
    std::cout << this->getName() << " se réveille dans la décharge et dit : " << "Hahaha, hahaha, je ressuscite." << std::endl;
}

NinjaTrap::NinjaTrap(std::string const &name)
    : _hit_points((unsigned int)100), _max_hit_points((unsigned int)100),_energy_points((unsigned int)100), _max_energy_points((unsigned int)100),
    _level((unsigned int)1), _name(name),_melee_attack((unsigned int)30), _ranged_attack((unsigned int)20),_armor_damage_reduction((unsigned int)5) {
    srand (time(NULL));
    std::cout << this->getName() << " se réveille dans la décharge et dit : " << "Hahaha, hahaha, je ressuscite." << std::endl;
}

NinjaTrap::NinjaTrap (NinjaTrap const &src) {
    *this = src;
    return ;
}

NinjaTrap::~NinjaTrap() {
    std::cout << this->getName() << " meurt et dit : " << "Est-ce que ça veut dire que je peux danser ? Steuplaiiiiiit !" << std::endl;
}

NinjaTrap    &NinjaTrap::operator=(NinjaTrap const & rhs) {
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

unsigned int NinjaTrap::getHitPoints() const {
    return this->_hit_points;
}

void NinjaTrap::setHitPoints(unsigned int hitPoints) {
    if (hitPoints > this->getMaxHitPoints()){
        this->_hit_points = this->getMaxHitPoints();
    }
    else{
        this->_hit_points = hitPoints;
    }
    if (this->_hit_points == (unsigned int)0){
        std::cout << "FR4G-TP <" << this->_name << "> est hors-service..." << std::endl;
    }
}

unsigned int NinjaTrap::getMaxHitPoints() const {
    return this->_max_hit_points;
}

void NinjaTrap::setMaxHitPoints(unsigned int maxHitPoints) {
    this->_max_hit_points = maxHitPoints;
}

unsigned int NinjaTrap::getMaxEnergyPoints() const {
    return this->_max_energy_points;
}

void NinjaTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints) {
    this->_max_energy_points = maxEnergyPoints;
}

unsigned int NinjaTrap::getEnergyPoints() const {
    return this->_energy_points;
}

void NinjaTrap::setEnergyPoints(unsigned int energyPoints) {
    if (energyPoints > this->getMaxEnergyPoints()){
        this->_energy_points = this->getMaxEnergyPoints();
    }
    else{
        this->_energy_points = energyPoints;
    }
}

unsigned int NinjaTrap::getLevel() const {
    return this->_level;
}

void NinjaTrap::setLevel(unsigned int level) {
    this->_level = level;
}

const std::string &NinjaTrap::getName() const {
    return this->_name;
}

void NinjaTrap::setName(const std::string &name) {
    this->_name = name;
}

unsigned int NinjaTrap::getMeleeAttack() const {
    return this->_melee_attack;
}

void NinjaTrap::setMeleeAttack(unsigned int meleeAttack) {
    this->_melee_attack = meleeAttack;
}

unsigned int NinjaTrap::getRangedAttack() const {
    return this->_ranged_attack;
}

void NinjaTrap::setRangedAttack(unsigned int rangedAttack) {
    this->_ranged_attack = rangedAttack;
}

unsigned int NinjaTrap::getArmorDamageReduction() const {
    return this->_armor_damage_reduction;
}

void NinjaTrap::setArmorDamageReduction(unsigned int armorDamageReduction) {
    this->_armor_damage_reduction = armorDamageReduction;
}

unsigned int NinjaTrap::meleeAttack(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> attaque <" << target << "> au corp a corp, causant <" << this->getMeleeAttack() << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack();
    }
}

unsigned int NinjaTrap::echappementCryogénique(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> attaque <" << target << "> avec Échappement cryogénique, causant <" << this->getMeleeAttack() * 1 << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack() * 1;
    }
}

unsigned int NinjaTrap::rireDiabolique(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> attaque <" << target << "> avec Rire diabolique (Mouhahahahaha), causant <" << this->getMeleeAttack() * 0 << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack() * 0;
    }
}

unsigned int NinjaTrap::grenadeDeLaColere(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> attaque <" << target << "> avec Grenade de la colère, causant <" << this->getRangedAttack() * 1 << "> points de dégâts !" << std::endl;
        return this->getRangedAttack() * 1;
    }
}

unsigned int NinjaTrap::machineDeMort(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> attaque <" << target << "> avec Machine de mort, causant <" << this->getMeleeAttack() * 2 << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack() * 2;
    }
}

unsigned int NinjaTrap::punchDHyperion(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> attaque <" << target << "> avec Punch d'Hyperion, causant <" << this->getRangedAttack() * 0.5 << "> points de dégâts !" << std::endl;
        return this->getRangedAttack() * 0.5;
    }
}

unsigned int NinjaTrap::rangedAttack(const std::string &target) const {
    if (this->getHitPoints() == 0){
        std::cout << "FR4G-TP <" << this->_name << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->_name << ">..." << std::endl;
        return 0;
    }
    else {
        std::cout << "FR4G-TP <" << this->_name << "> attaque <" << target << "> à distance, causant <"
                  << this->getRangedAttack() << "> points de dégâts !" << std::endl;
        return this->getRangedAttack();
    }
}

void NinjaTrap::takeDamage(unsigned int amount) {
    if (amount < this->getArmorDamageReduction()){
        std::cout << "FR4G-TP <" << this->_name << "> se fait frapper mais ce n'est pas très efficace..." << std::endl;
    }
    else{
        std::cout << "FR4G-TP <" << this->_name << "> se fait frapper et reçoit <" << amount << "> point de dégats. Après réduction de l'armure, il pert : <" <<amount - this->getArmorDamageReduction() << "> points de vie !" << std::endl;
        if (this->getHitPoints() > (amount - this->getArmorDamageReduction())){
            this->setHitPoints(this->getHitPoints() - (amount - this->getArmorDamageReduction()));
        }
        else{
            this->setHitPoints((unsigned int)0);
        }
    }

}

void NinjaTrap::beRepaired(unsigned int amount) {
    this->setHitPoints(this->getHitPoints() + amount);
    std::cout << "FR4G-TP <" << this->_name << "> se répare! Il a maintenant : <" <<this->getHitPoints() << "> points de vie !" << std::endl;
}

void NinjaTrap::chargingBattery(unsigned int amount) {
    this->setEnergyPoints(this->getEnergyPoints() + amount);
    std::cout << "FR4G-TP <" << this->_name << "> se recharge! Il a maintenant : <" <<this->getEnergyPoints() << "> points d'energie !" << std::endl;
}

unsigned int NinjaTrap::vaulthunter_dot_exe(const std::string &target) {
    if (this->getEnergyPoints() < 25){
        std::cout << "FR4G-TP <" << this->_name << "> n'a plus d'energie..." << std::endl;
        return 0;
    }
    else{
        this->setEnergyPoints(this->getEnergyPoints() - 25);
        unsigned int (NinjaTrap::*p[5])(const std::string &target) const = {
                &NinjaTrap::machineDeMort,
                &NinjaTrap::rireDiabolique,
                &NinjaTrap::echappementCryogénique,
                &NinjaTrap::punchDHyperion,
                &NinjaTrap::grenadeDeLaColere,
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
