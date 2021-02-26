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
    virtual ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);
    bool    operator==(Fixed const & rhs) const ;
    bool    operator!=(Fixed const & rhs) const ;
    bool    operator<=(Fixed const & rhs) const ;
    bool    operator>=(Fixed const & rhs) const ;
    bool    operator<(Fixed const & rhs) const ;
    bool    operator>(Fixed const & rhs) const ;
    Fixed   operator+(Fixed const & rhs) const ;
    Fixed   operator-(Fixed const & rhs) const ;
    Fixed   operator*(Fixed const & rhs) const ;
    Fixed   operator/(Fixed const & rhs) const ;
    Fixed & operator++(void);
    Fixed   operator++(int);
    Fixed & operator--(void);
    Fixed   operator--(int);

    int getRawBits() const;
    void setRawBits(int const value);

    float toFloat(void) const;
    int toInt(void) const;


private:
    int _fixedPointValue;
    int const static _fractBits = 8;
};

int &max(int &a, int &b);
const int &max(const int &a, const int &b);

int &min(int &a, int &b);
const int &min(const int &a, const int &b);

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //OLD_CPP_MODULE_FIXED_HPP
