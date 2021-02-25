#ifndef OLD_CPP_MODULE_FIXED_HPP
#define OLD_CPP_MODULE_FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed(void);
    virtual ~Fixed(void);

    Fixed(Fixed const &copy);
    Fixed & operator=(Fixed const & rhs);

    int getRawBits() const;
    void setRawBits(int const raw);

private:
    int _value;
    int const static _nb_bits = 8;

};

#endif //OLD_CPP_MODULE_FIXED_HPP
