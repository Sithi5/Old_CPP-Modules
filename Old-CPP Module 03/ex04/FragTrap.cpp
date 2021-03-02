#include "FragTrap.hpp"

FragTrap::FragTrap(void)
    : ClapTrap() {
    this->setMaxEnergyPoints(100);
    this->setEnergyPoints(100);
    this->setArmorDamageReduction(5);
    this->setMeleeAttack(30);
    this->setRangedAttack(20);
}

FragTrap::FragTrap(std::string const &name)
    : ClapTrap(name) {
    this->setMaxEnergyPoints(100);
    this->setEnergyPoints(100);
    this->setArmorDamageReduction(5);
    this->setMeleeAttack(30);
    this->setRangedAttack(20);
}

FragTrap::~FragTrap() {}

FragTrap    &FragTrap::operator=(FragTrap const & rhs) {
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

unsigned int FragTrap::meleeAttack(const std::string &target, std::string const &type) const {
    if (this->getHitPoints() == 0){
        std::cout << type << " <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << type << " <" << this->getName() << "> attaque <" << target << "> au corp a corp, causant <" << this->getMeleeAttack() << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack();
    }
}

unsigned int FragTrap::rangedAttack(const std::string &target, std::string const &type) const {
    if (this->getHitPoints() == 0){
        std::cout << type << " <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else {
        std::cout << type << " <" << this->getName() << "> attaque <" << target << "> à distance, causant <"
                  << this->getRangedAttack() << "> points de dégâts !" << std::endl;
        return this->getRangedAttack();
    }
}


unsigned int FragTrap::echappementCryogénique(const std::string &target, std::string const &type) const {
    if (this->getHitPoints() == 0){
        std::cout << type << " <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << type << " <" << this->getName() << "> attaque <" << target << "> avec Échappement cryogénique, causant <" << this->getMeleeAttack() * 1 << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack() * 1;
    }
}

unsigned int FragTrap::rireDiabolique(const std::string &target, std::string const &type) const {
    if (this->getHitPoints() == 0){
        std::cout << type << " <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << type << " <" << this->getName() << "> attaque <" << target << "> avec Rire diabolique (Mouhahahahaha), causant <" << this->getMeleeAttack() * 0 << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack() * 0;
    }
}

unsigned int FragTrap::grenadeDeLaColere(const std::string &target, std::string const &type) const {
    if (this->getHitPoints() == 0){
        std::cout << type << " <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << type << " <" << this->getName() << "> attaque <" << target << "> avec Grenade de la colère, causant <" << this->getRangedAttack() * 1 << "> points de dégâts !" << std::endl;
        return this->getRangedAttack() * 1;
    }
}

unsigned int FragTrap::machineDeMort(const std::string &target, std::string const &type) const {
    if (this->getHitPoints() == 0){
        std::cout << type << " <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << type << " <" << this->getName() << "> attaque <" << target << "> avec Machine de mort, causant <" << this->getMeleeAttack() * 2 << "> points de dégâts !" << std::endl;
        return this->getMeleeAttack() * 2;
    }
}

unsigned int FragTrap::punchDHyperion(const std::string &target, std::string const &type) const {
    if (this->getHitPoints() == 0){
        std::cout << type << " <" << this->getName() << "> est hors-service, il faut le réparer !!! Pauvre <"<< this->getName() << ">..." << std::endl;
        return 0;
    }
    else{
        std::cout << type << " <" << this->getName() << "> attaque <" << target << "> avec Punch d'Hyperion, causant <" << this->getRangedAttack() * 0.5 << "> points de dégâts !" << std::endl;
        return this->getRangedAttack() * 0.5;
    }
}

unsigned int FragTrap::vaulthunter_dot_exe(const std::string &target, std::string const &type) {
    if (this->getEnergyPoints() < 25){
        std::cout << type << " <" << this->getName() << "> n'a plus d'energie..." << std::endl;
        return 0;
    }
    else{
        this->setEnergyPoints(this->getEnergyPoints() - 25);
        unsigned int (FragTrap::*p[5])(const std::string &target, std::string const &type) const = {
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
                return (this->*p[i])(target, type);
            }
        }
        return 0;
    }
}
