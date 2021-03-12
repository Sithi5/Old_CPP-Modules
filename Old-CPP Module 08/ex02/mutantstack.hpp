#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack(void);
    MutantStack(MutantStack const &copy);
    virtual ~MutantStack(void);
    MutantStack<T> &operator=(MutantStack<T> const &rhs);

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    iterator begin(void);
    reverse_iterator rbegin(void);
    iterator end(void);
    reverse_iterator rend(void);
};

#endif
