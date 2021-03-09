#include <iomanip>
#include "Litteral.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Program must receive exactly one arg." << std::endl;
        return 0;
    }

    std::string input = av[1];
    Litteral litteral = Litteral(input);

//    printing char conversion
    try{
        char c = static_cast<char>(litteral);
        if (c <= 31 || c >= 127){
            std::cout << "char: " << "not printable" << std::endl;
        }
        else{
            std::cout << "char: " << c << std::endl;
        }
    }
    catch(std::exception const &e){
        std::cerr << e.what() << std::endl;
    }

    //    printing int conversion
    try{
        int i = static_cast<int>(litteral);
        std::cout << "int: " << i << std::endl;
    }
    catch(std::exception const &e){
        std::cerr << e.what() << std::endl;
    }

    //    printing float conversion
    try{
        float f = static_cast<float>(litteral);
        std::cout << "float: " << f << std::endl;
    }
    catch(std::exception const &e){
        std::cerr << e.what() << std::endl;
    }

    //    printing float conversion
    try{
        double d = static_cast<double>(litteral);
        std::cout << "double: " << d << std::endl;
    }
    catch(std::exception const &e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


