#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack<T>() {}
    MutantStack<T>(MutantStack const &copy) : std::stack<T>(copy) {*this = copy;}
    virtual ~MutantStack<T>(void) {}
    MutantStack<T> &operator=(MutantStack<T> const &rhs) {
        (void)rhs;
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    iterator begin(void) { return std::stack<T>::c.begin();}
    reverse_iterator rbegin(void) { return std::stack<T>::c.rbegin();}
    iterator end(void) { return std::stack<T>::c.end();}
    reverse_iterator rend(void) { return std::stack<T>::c.rend();}
};

#endif
