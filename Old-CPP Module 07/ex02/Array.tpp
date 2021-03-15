#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <iostream>

class IndexOutOfRange : public std::exception {
public:
    virtual const char *what() const throw() { return ("Index out of range."); }
};

template<typename T>
class Array {
private:
    T *_array;
    unsigned int _size;
public:
    Array<T>(void) : _array(new T[0]), _size(0) {}

    Array<T>(unsigned int n) : _array(new T[n]), _size(n) {}

    Array<T>(Array const &copy): _array(new T[0]), _size(0){
        *this = copy;
    }

    Array &operator=(Array const &rhs){
        if (this != &rhs)
        {
            if (this->size() > 0){
                delete [] this->_array;
            }
            this->_size = rhs.size();
            this->_array = new T[this->size()];
            for (unsigned int i = 0; i < this->size(); i++){
                this->_array[i] = rhs.getArray()[i];
            }
        }
        return *this;
    }

    virtual ~Array<T>(void) {
        delete [] this->getArray();
    }

    unsigned int size() const {
        return this->_size;
    }

    T *getArray(void) const { return _array; }


    T &operator[](unsigned int n) throw(std::exception) {
        if (n >= this->size()) {
            throw IndexOutOfRange();
        } else {
            return this->getArray()[n];
        }
    }


};

#endif
