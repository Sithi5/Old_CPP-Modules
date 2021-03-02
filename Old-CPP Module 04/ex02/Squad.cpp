#include "Squad.hpp"

Squad::Squad(void) : _units(NULL) {}

Squad::~Squad(void) {
    for (int i = 0; i < this->getCount(); i++){
        delete this->_units[i];
    }
    delete [] this->_units;
}

Squad::Squad(const Squad &copy) {
    *this = copy;
}

Squad &Squad::operator=(const Squad &rhs) {
    if (this != &rhs)
    {
        for (int i = 0; i < this->getCount(); i++){
            delete this->_units[i];
            this->_units[i] = NULL;
        }
        for (int i = 0; i < rhs.getCount(); i++){
            this->push(rhs._units[i]);
        }
    }
    return (*this);
}

int Squad::getCount() const {
    int count = 0;
    while (this->_units && this->_units[count])
        count++;
    return count;
}

ISpaceMarine* Squad::getUnit(int N) const {
    if (N >= 0 && N < this->getCount())
        return this->_units[N];
    else
    {
        std::cout << "SpaceMarine number " << N;
        std::cout << " can't be found in this squad of " << this->getCount();
        std::cout << " SpaceMarines" << std::endl;
    }
    return NULL;
}

int Squad::push(ISpaceMarine *newSpaceMarine) {
    if (newSpaceMarine != NULL)
    {
        for (int i = 0; i < this->getCount(); i++)
            if (this->_units[i] == newSpaceMarine)
                return -1;
        this->_units[this->getCount()] = newSpaceMarine;
    }
    return this->getCount();
}
