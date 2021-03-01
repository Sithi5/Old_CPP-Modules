#ifndef OLD_CPP_MODULES_PONY_HPP
#define OLD_CPP_MODULES_PONY_HPP

#include <iostream>

class Pony
{
public:
    Pony(std::string name, std::string color, int age, std::string death);
    ~Pony(void);
    void talk(void) const;
    void setName(std::string name);
    void setColor(std::string color);
    void setAge(int age);
    void setDeath(std::string death);
    std::string getName(void);
    std::string getColor(void);
    int getAge(void);
    std::string getDeath(void);

private:
    std::string _name;
    std::string _color;
    int _age;
    std::string _death;
};

#endif //OLD_CPP_MODULES_PONY_HPP
