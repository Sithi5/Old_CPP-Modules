#ifndef EX03_ICE_HPP
#define EX03_ICE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
    Cure();

    Cure(Cure const &copy);

    Cure &operator=(Cure const &rhs);

    virtual void use(ICharacter &target);

    virtual Cure *clone() const;
};


#endif //EX03_ICE_HPP
