
#include "span.hpp"

Span::Span(unsigned int storedNb) : _max_stored_number(storedNb), _container(0)
{
}

Span::Span(Span const &copy) : _max_stored_number(copy.getMaxStoredNb()), _container(0) { *this = copy; }

Span::~Span()
{
    this->_container.clear();
}

Span &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        this->_container = rhs._container;
    }
    return (*this);
}

void Span::addNumber(unsigned int nb) throw(Span::ContainerIsFull)
{
    if (this->getContainer().size() < this->getMaxStoredNb())
    {
        this->_container.push_back(nb);
    }
    else
    {
        throw Span::ContainerIsFull();
    }
}

unsigned int Span::getMaxStoredNb() const
{
    return _max_stored_number;
}

void Span::setMaxStoredNb(unsigned int storedNb)
{
    _max_stored_number = storedNb;
}

const std::vector<int> &Span::getContainer() const
{
    return _container;
}

void Span::setContainer(const std::vector<int> &container)
{
    _container = container;
}

int Span::shortestSpan() throw(Span::NotEnoughtElements)
{
    if (this->getContainer().size() < 2)
    {
        throw Span::NotEnoughtElements();
    }
    std::vector<int> copy_container(this->_container);
    std::sort(copy_container.begin(), copy_container.end());
    std::vector<int> substracted_int;

    for (std::vector<int>::iterator it = copy_container.begin(); it != copy_container.end() - 1; ++it)
    {
        substracted_int.push_back(*(it + 1) - *it);
    }
    int smallest = *(std::min_element(substracted_int.begin(), substracted_int.end()));

    return smallest;
}

int Span::longestSpan() throw(Span::NotEnoughtElements)
{
    if (this->getContainer().size() < 2)
    {
        throw Span::NotEnoughtElements();
    }
    int biggest = *(std::max_element(this->_container.begin(), this->_container.end()));
    int smallest = *(std::min_element(this->_container.begin(), this->_container.end()));

    return biggest - smallest;
}

const char *Span::ContainerIsFull::what() const throw()
{
    return "The container is full.";
}

const char *Span::NotEnoughtElements::what() const throw()
{
    return "The container has not enought element to execute the action.";
}