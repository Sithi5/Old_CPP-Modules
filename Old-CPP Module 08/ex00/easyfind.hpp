
#ifndef TEST_EASYFIND_HPP
#define TEST_EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>
#include <sstream>

template <typename T>
int easyfind(T container, int item) throw(std::exception)
{
    typename T::iterator it;

    if ((it = std::find(container.begin(), container.end(), item)) != container.end())
    {
        return std::distance(container.begin(), it);
    }
    else
    {
        std::stringstream ss;
        ss << "item " << item << " was not found in the container.";
        throw std::runtime_error(ss.str().c_str());
    }
}

#endif //TEST_EASYFIND_HPP
