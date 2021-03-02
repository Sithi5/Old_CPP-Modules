#include "Squad.hpp"

Squad::Squad() {}

Squad::~Squad() {
    for (int i = 0; i < this->_n - 1; i++){
        delete this->_units[i];
    }
}

Squad::Squad(const Squad &copy) {
    *this = copy;
}

Squad &Squad::operator=(const Squad &rhs) {
    if (this != &rhs)
    {
        for (int i = 0; i < this->getCount() - 1; i++){
            delete this->_units[i];
        }
        for (int i = 0; i < rhs._n - 1; i++){
            this->push(rhs._units[i]);
        }
        this->_n = rhs.getCount();
    }
    return (*this);
}

int Squad::getCount() const {
    return 0;
}

ISpaceMarine* Squad::getUnit(int N) const {
    return nullptr;
}

int Squad::push(ISpaceMarine *) {

}
