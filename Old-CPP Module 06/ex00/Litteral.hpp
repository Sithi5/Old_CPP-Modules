
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


    operator char() const;

    operator int() const;

    operator float() const;

    operator double() const;


    const std::string &getLitteralType() const;

    void setLitteralType(const std::string &litteralType);

    const std::string &getInput() const;

    void setInput(const std::string &input);

    int getLitteralInt() const;

    void setLitteralInt(int litteralInt);

    char getLitteralChar() const;

    void setLitteralChar(char litteralChar);

    float getLitteralFloat() const;

    void setLitteralFloat(float litteralFloat);

    double getLitteralDouble() const;

    void setLitteralDouble(double litteralDouble);

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
