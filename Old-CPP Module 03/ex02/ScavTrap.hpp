#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
    explicit ScavTrap(std::string const &name);
    explicit ScavTrap(void);
    ~ScavTrap(void);

    void challengeNewcomer(void);

protected:
    static std::string _challenges[3];
};

#endif