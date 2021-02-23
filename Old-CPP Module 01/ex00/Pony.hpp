#ifndef OLD_CPP_MODULES_PONY_HPP
# define OLD_CPP_MODULES_PONY_HPP

#include <iostream>

class Pony {
public:
    Pony(std::string name, std::string color, int age, std::string death);
    ~Pony();
    void talk(void) const;

private:
    std::string _name;
    std::string _color;
    int _age;
    std::string _death;

};


#endif //OLD_CPP_MODULES_PONY_HPP
