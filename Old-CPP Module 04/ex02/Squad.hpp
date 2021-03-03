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

    typedef struct      s_list{
        ISpaceMarine    *unit;
        struct s_list   *next;
    }                   t_list;

    t_list *_units_list;
};

#endif