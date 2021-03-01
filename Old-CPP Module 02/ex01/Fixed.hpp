#ifndef OLD_CPP_MODULE_FIXED_HPP
#define OLD_CPP_MODULE_FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed {
public:
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(Fixed const &copy);
    ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);

    int getRawBits() const;
    void setRawBits(int const value);

    float toFloat(void) const;
    int toInt(void) const;


private:
    int _fixedPointValue;
    int const static _fractBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
