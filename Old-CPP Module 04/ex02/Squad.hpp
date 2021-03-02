#ifndef TEST_SQUAD_HPP
#define TEST_SQUAD_HPP

#include "ISquad.hpp"
#include <iostream>

class Squad: public ISquad {
public:
    Squad(void);
    Squad(Squad const &copy);
    virtual ~Squad(void);

    Squad & operator=(const Squad &rhs);

    virtual int getCount() const;
    virtual ISpaceMarine* getUnit(int N) const;
    virtual int push(ISpaceMarine *);

private:
    ISpaceMarine **_units;
};

#endif