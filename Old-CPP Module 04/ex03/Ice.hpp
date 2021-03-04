#ifndef EX03_ICE_HPP
#define EX03_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();

    Ice(Ice const &copy);

    Ice &operator=(Ice const &rhs);

    virtual void use(ICharacter &target);

    virtual AMateria *clone() const;
};


#endif //EX03_ICE_HPP
