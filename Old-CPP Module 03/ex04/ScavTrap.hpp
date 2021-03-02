#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
    explicit ScavTrap(std::string const &name);
    explicit ScavTrap(void);
    ScavTrap(ScavTrap const &src);
    ~ScavTrap(void);

    unsigned int meleeAttack(std::string const &target) const;
    unsigned int rangedAttack(std::string const &target) const;

    void challengeNewcomer(void);

protected:
    static std::string _challenges[3];
};

#endif