#include "MiningBarge.hpp"

MiningBarge::MiningBarge() {}

MiningBarge::MiningBarge(MiningBarge const &copy) {
    for (int i = 0; i < 4; i++)
        if (copy._lasers[i])
            this->equip(copy._lasers[i]);
        else
            this->_lasers[i] = NULL;
}

MiningBarge::~MiningBarge() {}

MiningBarge &MiningBarge::operator=(MiningBarge const &rhs){
    for (int i = 0; i < 4; i++)
        if (rhs._lasers[i])
            this->equip(rhs._lasers[i]);
        else
            this->_lasers[i] = NULL;
    return (*this);
}

void MiningBarge::equip(IMiningLaser *m) {
    for (int i = 0; i < 4; i++) {
        if (!this->_lasers[i]) {
            this->_lasers[i] = m;
            return;
        }
    }
    std::cout << "Barge lasers is full" << std::endl;
}

void    MiningBarge::mine(IAsteroid *asteroid) const{
    for (int i = 0; i < 4; i++){
        if (this->_lasers[i]){
            this->_lasers[i]->mine(asteroid);
        }
    }
}