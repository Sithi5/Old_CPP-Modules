#ifndef EX03_MATERIASOURCE_HPP
#define EX03_MATERIASOURCE_HPP


#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria *m);

    virtual AMateria *createMateria(std::string const &type);

private:
    AMateria *_knowledge[4];
};

#endif //EX03_MATERIASOURCE_HPP
