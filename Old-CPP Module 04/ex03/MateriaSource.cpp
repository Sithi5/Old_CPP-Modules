#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        this->_knowledge[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!this->_knowledge[i]) {
            this->_knowledge[i] = m->clone();
            return;
        }
    }
    std::cout << "Knowledge is full" << std::endl;
    return;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < 4; i++) {
        if (!(this->_knowledge[i]->getType().compare(type))) {
            return this->_knowledge[i]->clone();
        }
    }
    return NULL;
}
