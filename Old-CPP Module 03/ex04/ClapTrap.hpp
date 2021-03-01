#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <stdlib.h>
# include <time.h>

class ClapTrap {
public:
    ClapTrap(void);
    ClapTrap(std::string const &name);
    ClapTrap(ClapTrap const &src);
    ~ClapTrap();

    ClapTrap & operator=(ClapTrap const &rhs);


    void setHitPoints(unsigned int hitPoints);
    void setMaxHitPoints(unsigned int maxHitPoints);
    void setMaxEnergyPoints(unsigned int maxEnergyPoints);
    void setEnergyPoints(unsigned int energyPoints);
    void setLevel(unsigned int level);
    void setName(const std::string &name);
    void setMeleeAttack(unsigned int meleeAttack);
    void setRangedAttack(unsigned int rangedAttack);
    void setArmorDamageReduction(unsigned int armorDamageReduction);

    unsigned int getMaxHitPoints() const;
    unsigned int getHitPoints() const;
    unsigned int getMaxEnergyPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getLevel() const;
    const std::string &getName() const;
    unsigned int getMeleeAttack() const;
    unsigned int getRangedAttack() const;
    unsigned int getArmorDamageReduction() const;

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