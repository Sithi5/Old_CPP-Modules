#include "ZombieEvent.hpp"
#include <stdlib.h>

ZombieEvent::ZombieEvent(std::string type) : _type(type) {
    srand(time(0));
}
ZombieEvent::~ZombieEvent() {}

void ZombieEvent::setZombieType(std::string type) {
    this->_type = type;
}
Zombie *ZombieEvent::newZombie(std::string name) {
    Zombie *generated_zombie = new Zombie(name, this->_type);
    return generated_zombie;
}

std::string ZombieEvent::generateRandomName(void) const{
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string random_name = "";
    int name_len = rand() % 6 + 4;
    for (int i = 0; i < name_len; i++){
        random_name += (alphabet[rand() % alphabet.length()]);
    }
    return random_name;
}

Zombie *ZombieEvent::randomChump() {
    std::string random_name = this->generateRandomName();
    Zombie *generated_zombie = this->newZombie(random_name);
    generated_zombie->advert();
    return generated_zombie;
}