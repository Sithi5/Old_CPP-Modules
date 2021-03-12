#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void);
	MutantStack(MutantStack const &copy);
	virtual ~MutantStack(void);
	MutantStack & operator=(MutantStack const &rhs); 

	typedef typename std::stack<Tr>::container_type::iterator iterator;
	iterator begin(void) {return std::stack<T>::c.begin();}
	iterator rbegin(void);
	iterator end(void);
	iterator rend(void);
};

#endif