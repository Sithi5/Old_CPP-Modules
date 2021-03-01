#ifndef OLD_CPP_MODULE_FIXED_HPP
#define OLD_CPP_MODULE_FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed(void);
    ~Fixed(void);

    Fixed(Fixed const &copy);
    Fixed & operator=(Fixed const & rhs);

    int getRawBits() const;
    void setRawBits(int const value);

private:
    int _fixedPointValue;
    int const static _fractBits = 8;

};

#endif //OLD_CPP_MODULE_FIXED_HPP
