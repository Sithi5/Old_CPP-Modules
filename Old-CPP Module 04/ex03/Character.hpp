#ifndef EX03_CHARACTER_HPP
#define EX03_CHARACTER_HPP


#include "ICharacter.hpp"

class Character : public ICharacter {

public:
    Character(const std::string &name);

    Character(Character const &copy);

    Character &operator=(const Character &op);

    virtual ~Character() {}

    virtual std::string const &getName() const;

    virtual void equip(AMateria *m);

    virtual void unequip(int idx);

    virtual void use(int idx, ICharacter &target);

private:
    std::string _name;
    AMateria *_inventory[4];
};


#endif //EX03_CHARACTER_HPP
