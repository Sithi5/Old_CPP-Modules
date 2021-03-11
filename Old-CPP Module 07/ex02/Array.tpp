#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <iostream>

template<typename T>
class Array
{
private:
	T *_array;
public:
	Array(void): _array(new T[0]) {};
	Array(unsigned int n): _array(new T[n]) {};
	Array(Array const &copy): _array(copy.getArray()) {};
	virtual ~Array(void);

	T & operator[](unsigned int n) throw() {
		if (n >= len(this->getArray()))
			throw std::exception("Index out of range.");
		return this->getArray()[n];
	};
	T * getArray(void) {return _array;};
};

#endif
