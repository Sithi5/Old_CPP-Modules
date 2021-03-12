
#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void): std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &copy) : std::stack<T>(copy) {*this = copy;}

template <typename T>
MutantStack<T>::~MutantStack(void){}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const &rhs) {
	(void)rhs;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator begin(void) { return std::stack<T>::c.begin();}
template <typename T>
typename MutantStack<T>::reverse_iterator rbegin(void) { return std::stack<T>::c.rbegin();}
template <typename T>
typename MutantStack<T>::iterator end(void) { return std::stack<T>::c.end();}
template <typename T>
typename MutantStack<T>::reverse_iterator rend(void) { return std::stack<T>::c.rend();}
