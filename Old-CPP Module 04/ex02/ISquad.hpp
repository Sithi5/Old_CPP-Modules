#ifndef TEST_ISQUAD_HPP
#define TEST_ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad {
public:
    virtual ~ISquad() {}
    virtual int getCount() const = 0;
    virtual ISpaceMarine* getUnit(int) const = 0;
    virtual int push(ISpaceMarine*) = 0;
};


#endif //TEST_ISQUAD_HPP