#ifndef TEST_AMATERIAL_HPP
#define TEST_AMATERIAL_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
private:
    std::string const _type;
    unsigned int _xp;

protected:
    AMateria();

public:
    AMateria(const std::string &type);

    virtual ~AMateria();

    std::string const &getType() const; //Returns the materia type
    virtual AMateria *clone() const = 0;

    virtual void use(ICharacter &target);

    unsigned int getXP() const; //Returns the Materia's XP

    void setXp(unsigned int xp);
};


#endif //TEST_AMATERIAL_HPP
