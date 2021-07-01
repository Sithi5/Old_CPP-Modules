#include "span.hpp"
#include <iostream>

int main()
{
    srand(time(NULL));
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Testing with big numbers possibility : " << std::endl;
    std::cout << std::endl;

    Span sp2 = Span(10);

    for (unsigned int y = 0; y < sp2.getMaxStoredNb(); y++)
    {
        sp2.addNumber(rand() % 100);
    }
    std::cout << "printing elem of the container : " << std::endl;

    for (std::vector<int>::const_iterator i = sp2.getContainer().begin(); i != sp2.getContainer().end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Testing with lot of numbers: " << std::endl;
    std::cout << std::endl;

    Span sp3 = Span(20000);

    for (unsigned int y = 0; y < sp3.getMaxStoredNb(); y++)
    {
        sp3.addNumber(rand() % 10000000000);
    }
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;
}
