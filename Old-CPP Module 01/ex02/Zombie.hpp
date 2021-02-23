#ifndef OLD_CPP_MODULES_ZOMBIE_HPP
#define OLD_CPP_MODULES_ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
    Zombie(std::string type, std::string name);
    ~Zombie(void);
    void announce(void) const;
private:
    std::string _type;
    std::string _name;

};


#endif //OLD_CPP_MODULES_ZOMBIE_HPP
