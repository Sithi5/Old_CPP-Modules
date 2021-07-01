
#ifndef TEST_SPAN_HPP
#define TEST_SPAN_HPP

#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

class Span
{

public:
    Span(unsigned int storedNb);
    Span(Span const &copy);
    virtual ~Span();

    Span &operator=(Span const &rhs);

    unsigned int getMaxStoredNb() const;

    void setMaxStoredNb(unsigned int storedNb);

    const std::vector<int> &getContainer() const;

    void setContainer(const std::vector<int> &container);

    class ContainerIsFull : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class NotEnoughtElements : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    void addNumber(unsigned int nb) throw(ContainerIsFull);
    int shortestSpan() throw(NotEnoughtElements);
    int longestSpan() throw(NotEnoughtElements);

private:
    Span();
    unsigned int _max_stored_number;
    std::vector<int> _container;
};

#endif //TEST_SPAN_HPP
