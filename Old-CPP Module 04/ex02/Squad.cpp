#include "Squad.hpp"

Squad::Squad(void) : _units_list(NULL) {
}

Squad::~Squad(void) {
    if (this->_units_list){
        t_list *prev = this->_units_list;
        while (this->_units_list) {
            this->_units_list = this->_units_list->next;
            delete prev->unit;
            delete prev;
            prev = this->_units_list;
        }
    }
}

Squad::Squad(const Squad &copy) {
    if (this != &copy)
    {
        if (this->_units_list) {

            t_list *prev = this->_units_list;
            while (this->_units_list) {
                this->_units_list = this->_units_list->next;
                delete prev->unit;
                delete prev;
            }
        }
        t_list *copy_units_list = copy._units_list;
        while (copy_units_list) {
            this->push(copy_units_list->unit->clone());
            copy_units_list = copy_units_list->next;
        }
    }
}

Squad &Squad::operator=(const Squad &rhs) {
    if (this != &rhs)
    {
        if (this->_units_list){
            t_list *prev = this->_units_list;
            while (this->_units_list) {
                this->_units_list = this->_units_list->next;
                delete prev->unit;
                delete prev;
            }
        }

        t_list *rhs_units_list = rhs._units_list;
        while (rhs_units_list) {
            this->push(rhs_units_list->unit->clone());
            rhs_units_list = rhs_units_list->next;
        }
    }
    return (*this);
}

int Squad::getCount() const {
    t_list *list = this->_units_list;
    int count = 0;

    while (list){
        count++;
        list = list->next;
    }
    return count;
}

ISpaceMarine* Squad::getUnit(int N) const {
    t_list *list = this->_units_list;

    if (N >= 0 && N < this->getCount()){
        while (N > 0){
            list = list->next;
            N--;
        }
        return list->unit;
    }
    else
    {
        std::cout << "SpaceMarine number " << N;
        std::cout << " can't be found in this squad of " << this->getCount();
        std::cout << " SpaceMarines" << std::endl;
    }
    return NULL;
}

int Squad::push(ISpaceMarine *newSpaceMarine) {
    if (newSpaceMarine != NULL)
    {
        if (this->_units_list){
            if (this->_units_list->unit == newSpaceMarine){
                std::cout << "The unit is already in the squad." << std::endl;
                return 1;
            }
            t_list *root = this->_units_list;
            t_list *new_unit = new t_list;
            new_unit->next = NULL;
            new_unit->unit = newSpaceMarine;

            while (this->_units_list->next) {
                this->_units_list = this->_units_list->next;
                if (this->_units_list->unit == newSpaceMarine){
                    std::cout << "The unit is already in the squad." << std::endl;
                    delete new_unit;
                    this->_units_list = root;
                    return 1;
                }
            }
            this->_units_list->next = new_unit;
            this->_units_list = root;
            return 0;
        }
        else{
            this->_units_list = new t_list;
            this->_units_list->next = NULL;
            this->_units_list->unit = newSpaceMarine;
            return 0;
        }
    }
    std::cout << "Cannot add a NULL unit ;)." << std::endl;
    return 1;
}
