#include <iostream>

int     main(void){
    std::string str = "HI THIS IS BRAIN";
    std::string *p;
    std::string &ref = str;

    p = &str;

    std::cout << *p << std::endl;
    std::cout << ref << std::endl;
}