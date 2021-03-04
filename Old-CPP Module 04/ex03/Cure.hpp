#ifndef EX03_CURE_HPP
#define EX03_CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();

    Cure(Cure const &copy);

    Cure &operator=(Cure const &rhs);

    virtual void use(ICharacter &target);

    virtual AMateria *clone() const;
};


#endif //EX03_CURE_HPP
