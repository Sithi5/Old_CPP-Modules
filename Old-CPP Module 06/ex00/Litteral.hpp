
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


    operator char() const throw(ImpossibleConversion);

    operator int() const throw(ImpossibleConversion);

    operator float() const throw(ImpossibleConversion);

    operator double() const throw(ImpossibleConversion);

    bool LitteralIsChar();
    bool LitteralIsInt();
    bool LitteralIsFloat();
    bool LitteralIsDouble();

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

    class ImpossibleConversion : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

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
