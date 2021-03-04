#include "Character.hpp"

Character::Character(const std::string &name) : _name(name) {
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::Character(Character const &copy) : {
    if (this != &copy) {
        this->_name = std::string(copy.getName());
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i]) {
                delete this->_inventory[i];
            }
            if (copy._inventory[i]) {
                this->_inventory[i] = copy._inventory[i]->clone();
            }
        }
    }
}

Character &Character::operator=(const Character &op) {
    if (this != &op) {
        this->_name = op.getName();
        for (int i = 0; i < 4; i++) {
            this->_inventory[i] = op._inventory[i];
        }
    }
    return *this;
}

const std::string &Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i]) {
            this->_inventory[i] = m;
            return;
        }
    }
    std::cout << "Inventory is full" << std::endl;
    return;
}

void Character::unequip(int idx) {
    if (this->_inventory[idx]) {
        this->_inventory[idx] = NULL;
    } else {
        std::cout << "There is nothing to unequip at the index : " << idx << "." << std::endl;
    }
    return;
}

void Character::use(int idx, Character &target) {
    if (this->_inventory[idx]) {
        this->_inventory[idx]->use(target);
    } else {
        std::cout << "There is nothing to use at the index : " << idx << "." << std::endl;
    }
    return;
}



