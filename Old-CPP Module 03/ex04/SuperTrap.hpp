#ifndef TEST_SUPERTRAP_HPP
#define TEST_SUPERTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include <iostream>

class SuperTrap : public NinjaTrap, public FragTrap {
public:
    SuperTrap(void);
    SuperTrap(std::string const &name);
    ~SuperTrap();
    SuperTrap & operator=(SuperTrap const &rhs);

    unsigned int rangedAttack(std::string const &target, std::string const &type);
    unsigned int meleeAttack(std::string const &target, std::string const &type);
};

#endif
