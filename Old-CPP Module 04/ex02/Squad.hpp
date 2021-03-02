#ifndef TEST_SQUAD_HPP
#define TEST_SQUAD_HPP

#include "ISquad.hpp"

class Squad: public ISquad {
public:
    Squad();
    Squad(Squad const &copy);
    virtual ~Squad();

    Squad & operator=(const Squad &rhs);

    int getCount() const override;
    ISpaceMarine* getUnit(int N) const override;
    int push(ISpaceMarine *) override;

private:
    int _n;
    ISpaceMarine *_units[];

};


#endif //TEST_SQUAD_HPP
