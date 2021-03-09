
#ifndef TEST_LITTERAL_HPP
#define TEST_LITTERAL_HPP

#include <iostream>
#include "stdlib.h"

class Litteral {
public:
    Litteral(std::string &input);

    Litteral(Litteral const &cpy);

    Litteral &operator=(Litteral const &rhs);

    virtual ~Litteral();


    operator char();

    operator int();

    operator float();

    operator double();

private:
    Litteral();

    std::string _litteral_type;
    std::string _input;
    int         _litteral_int;
    char         _litteral_char;
    float         _litteral_float;
    double         _litteral_double;
};


#endif //TEST_LITTERAL_HPP
