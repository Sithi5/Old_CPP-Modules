
#ifndef TEST_LITTERAL_HPP
#define TEST_LITTERAL_HPP

#include <iostream>

class Litteral {
public:
    Litteral(std::string input);

    virtual ~Litteral();


    explicit operator char();

    explicit operator int();

    explicit operator float();

    explicit operator double();

private:
    std::string _input;
    double _litteral;
};


#endif //TEST_LITTERAL_HPP
