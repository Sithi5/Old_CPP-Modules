#ifndef TEST_FRAGTRAP_HPP
#define TEST_FRAGTRAP_HPP

#include <iostream>
#include <time.h>
#include <stdlib.h>

class NinjaTrap{
public:
    NinjaTrap(void);
    NinjaTrap(std::string const &name);
    NinjaTrap(NinjaTrap const &src);
    ~NinjaTrap();

    NinjaTrap & operator=(NinjaTrap const &rhs);

    unsigned int getHitPoints() const;

    void setHitPoints(unsigned int hitPoints);

    unsigned int getMaxHitPoints() const;

    void setMaxHitPoints(unsigned int maxHitPoints);

    unsigned int getMaxEnergyPoints() const;

    void setMaxEnergyPoints(unsigned int maxEnergyPoints);

    unsigned int getEnergyPoints() const;

    void setEnergyPoints(unsigned int energyPoints);

    unsigned int getLevel() const;

    void setLevel(unsigned int level);

    const std::string &getName() const;

    void setName(const std::string &name);

    unsigned int getMeleeAttack() const;

    void setMeleeAttack(unsigned int meleeAttack);

    unsigned int getRangedAttack() const;

    void setRangedAttack(unsigned int rangedAttack);

    unsigned int getArmorDamageReduction() const;

    void setArmorDamageReduction(unsigned int armorDamageReduction);

    unsigned int meleeAttack(std::string const &target) const;
    unsigned int rangedAttack(std::string const &target) const;
    unsigned int echappementCryogénique(std::string const &target) const;
    unsigned int machineDeMort(std::string const &target) const;
    unsigned int rireDiabolique(std::string const &target) const;
    unsigned int punchDHyperion(std::string const &target) const;
    unsigned int grenadeDeLaColere(std::string const &target) const;
    unsigned int vaulthunter_dot_exe(std::string const & target);

    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void chargingBattery(unsigned int amount);

protected:
    unsigned int _hit_points;
    unsigned int _max_hit_points;
    unsigned int _energy_points;
    unsigned int _max_energy_points;
    unsigned int _level;
    std::string _name;
    unsigned int _melee_attack;
    unsigned int _ranged_attack;
    unsigned int _armor_damage_reduction;
};

#endif
