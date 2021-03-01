#ifndef TEST_NINJATRAP_HPP
#define TEST_NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
#include <iostream>

class NinjaTrap : public ClapTrap{
public:
    NinjaTrap(void);
    NinjaTrap(std::string const &name);
    ~NinjaTrap();

    void ninjaShoeBox(FragTrap &claptrap);
    void ninjaShoeBox(ScavTrap &claptrap);
    void ninjaShoeBox(ClapTrap &claptrap);
    void ninjaShoeBox(NinjaTrap &claptrap);

};

#endif
