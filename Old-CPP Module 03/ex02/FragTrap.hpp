#ifndef TEST_FRAGTRAP_HPP
#define TEST_FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap{
public:
    FragTrap(void);
    FragTrap(std::string const &name);
    FragTrap(FragTrap const &src);
    ~FragTrap();
    FragTrap & operator=(FragTrap const &rhs);

    unsigned int meleeAttack(std::string const &target) const;
    unsigned int rangedAttack(std::string const &target) const;

    unsigned int echappementCryogénique(std::string const &target) const;
    unsigned int machineDeMort(std::string const &target) const;
    unsigned int rireDiabolique(std::string const &target) const;
    unsigned int punchDHyperion(std::string const &target) const;
    unsigned int grenadeDeLaColere(std::string const &target) const;
    unsigned int vaulthunter_dot_exe(std::string const & target);

};

#endif
