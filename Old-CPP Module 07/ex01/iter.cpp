#include <iostream>

template<typename T, typename U, typename R>
void iter(T *s1, U size, R(*func)(T)) {
    for (U i = 0; i < size; i++){
        func(s1[i]);
    }
}

template<typename T>
void print_elem(T elem){
    std::cout << elem << std::endl;
}

template<typename T>
T print_elem(T elem){
    std::cout << elem << std::endl;
    return elem;
}


int main(void) {
    char str[10] = "abcdefghl";
    int i = 10;
    ::iter<char , int, void>(str, i, &print_elem);
    ::iter<char , int, char>(str, i, &print_elem);

    int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned int i2 = 10;
    ::iter<int, unsigned int, void>(tab, i2, &print_elem);
    ::iter<int, unsigned int, int>(tab, i2, &print_elem);

    std::string str_tab[2] = {std::string("string one"), std::string("string two")};
    ::iter<std::string, int, void>(str_tab, (sizeof(str_tab)/sizeof (*str_tab)), &print_elem);
    ::iter<std::string, int, std::string>(str_tab, (sizeof(str_tab)/sizeof (*str_tab)), &print_elem);
}