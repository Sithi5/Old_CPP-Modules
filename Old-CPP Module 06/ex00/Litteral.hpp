
#ifndef TEST_LITTERAL_HPP
#define TEST_LITTERAL_HPP

#include <iostream>

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

    std::string _input;
};


#endif //TEST_LITTERAL_HPP
