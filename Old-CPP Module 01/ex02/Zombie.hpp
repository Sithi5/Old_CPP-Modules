#ifndef OLD_CPP_MODULES_ZOMBIE_HPP
#define OLD_CPP_MODULES_ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
    Zombie(std::string name, std::string type = "default");
    ~Zombie(void);

    void setType(std::string type);
    void setName(std::string name);

    std::string getType(void);
    std::string getName(void);

    void advert(void) const;
private:
    std::string _type;
    std::string _name;

};


#endif //OLD_CPP_MODULES_ZOMBIE_HPP
