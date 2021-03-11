#include "easyfind.hpp"
#include <iostream>

int main() {
    int index;
    std::vector<int> my_vec(10, 0);
    std::list<int> my_list(5, 100);
    std::deque<int> my_deck(8, 5);

    my_vec[9] = 5;
    my_list.push_back(-12398);
    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(-1);
    my_list.push_back(-2);

    my_deck[3] = -5;

    try {
        index = easyfind(my_vec, 5);
        std::cout << "item with value 5 has been found at index "  <<  index <<  " in the container." << std::endl;
        index = easyfind(my_list, -12398);
        std::cout << "item with value -12398 has been found at index "  << index  <<  " in the container." << std::endl;
        index = easyfind(my_list, 4897) ;
        std::cout << "item with value 4897 has been found at index "  << index <<  " in the container." << std::endl;
    }
    catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        index = easyfind(my_deck, -5);
        std::cout << "item with value -5 has been found at index "  << index <<  " in the container." << std::endl;
    }
    catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}