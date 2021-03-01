#ifndef OLD_CPP_MODULES_ZOMBIEEVENT_HPP
#define OLD_CPP_MODULES_ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent {
public:
    ZombieEvent(std::string type = "default");
    ~ZombieEvent();

    void setZombieType(std::string type);
    Zombie *newZombie(std::string name);
    Zombie *randomChump();

private:
    std::string _type;
    std::string generateRandomName(void) const;

};


#endif //OLD_CPP_MODULES_ZOMBIEEVENT_HPP
