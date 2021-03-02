#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
    ScavTrap(void);
    ScavTrap(std::string const &name);
    ~ScavTrap();
    ScavTrap & operator=(ScavTrap const &rhs);

    unsigned int meleeAttack(std::string const &target) const;
    unsigned int rangedAttack(std::string const &target) const;

    void challengeNewcomer(void);

protected:
    static std::string _challenges[3];
};

#endif