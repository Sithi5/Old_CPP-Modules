#ifndef TEST_NINJATRAP_HPP
#define TEST_NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class NinjaTrap : public virtual ClapTrap{
public:
    NinjaTrap(void);
    NinjaTrap(std::string const &name);
    ~NinjaTrap();

    unsigned int meleeAttack(std::string const &target, std::string const &type) const;
    unsigned int rangedAttack(std::string const &target, std::string const &type) const;

    void ninjaShoeBox(FragTrap &claptrap, std::string const &type);
    void ninjaShoeBox(ScavTrap &claptrap, std::string const &type);
    void ninjaShoeBox(ClapTrap &claptrap, std::string const &type);
    void ninjaShoeBox(NinjaTrap &claptrap, std::string const &type);

};

#endif
