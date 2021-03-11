#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <iostream>

class IndexOutOfRange : public std::exception
{
public:
    virtual const char *what() const throw() {return ("Index out of range.");}
};

template<typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;
public:
	Array(void): _array(new T[0]),_size(0) {}
	Array(unsigned int n): _array(new T[n]), _size(n) {}
	Array(Array const &copy): _array(copy.getArray()) {}
	virtual ~Array(void){}

    unsigned int size(){
        return this->_size;
    }

    T * getArray(void) {return _array;}



    T & operator[](unsigned int n) throw(std::exception) {
		if (n >= this->size()) {
            throw IndexOutOfRange();
        }
		else{
            return this->getArray()[n];
		}
	}


};

#endif
