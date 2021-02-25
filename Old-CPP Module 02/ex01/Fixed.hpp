//
// Created by MaSit on 25/02/2021.
//

#ifndef OLD_CPP_MODULE_FIXED_HPP
#define OLD_CPP_MODULE_FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(Fixed const &copy);
    virtual ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;


private:
    int _value;
    int const static _rawBits = 8;


};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //OLD_CPP_MODULE_FIXED_HPP
