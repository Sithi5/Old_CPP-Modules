#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
    ScavTrap(void);
    ScavTrap(std::string const &name);
    ScavTrap(ScavTrap const &src);
    virtual ~ScavTrap();

    ScavTrap & operator=(ScavTrap const &rhs);

    void challengeNewcomer(void);


protected:
    static std::string _challenges[3];
};

#endif