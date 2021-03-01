#ifndef TEST_SUPERTRAP_HPP
#define TEST_SUPERTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
# include <iostream>

class SuperTrap : public FragTrap, public NinjaTrap {
public:
    SuperTrap(void);
    SuperTrap(std::string const &name);
    ~SuperTrap();

    unsigned int meleeAttack(std::string const &target) const;
    unsigned int rangedAttack(std::string const &target) const;
};

#endif
