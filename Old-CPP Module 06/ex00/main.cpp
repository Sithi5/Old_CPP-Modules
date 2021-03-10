#include <iomanip>
#include "Litteral.hpp"

int main(int ac, char **av) {
    if (ac != 2 && ac != 3) {
        std::cout << "Program must receive at least one arg." << std::endl << "-first_arg = litteral." << std::endl
                  << "-second_arg = precision." << std::endl;
        return 0;
    }
    int precision = 1;
    if (ac == 3){
        int ret = atoi(av[2]);
        if (ret >= 0 && ret <= 20){
            precision = ret;
        }
        else{
            std::cout << "arg precision is incorrect. must be between 0 and 20" << std::endl;
        }
    }

    std::string input = av[1];
    try {
        Litteral litteral = Litteral(input);
        //    printing char conversion
        try {
            char c = static_cast<char>(litteral);
            if (c <= 31 || c >= 127) {
                std::cout << "char: " << "Non displayable" << std::endl;
            } else {
                std::cout << "char: \'" << c << "\'" << std::endl;
            }
        }
        catch (Litteral::ImpossibleConversion const &e) {
            std::cout << "char: " << "impossible" << std::endl;
        }
        catch (std::exception const &e) {
            std::cerr << e.what() << std::endl;
        }

        //    printing int conversion
        try {
            int i = static_cast<int>(litteral);
            std::cout << "int: " << i << std::endl;
        }
        catch (Litteral::ImpossibleConversion const &e) {
            std::cout << "int: " << "impossible" << std::endl;
        }
        catch (std::exception const &e) {
            std::cerr << e.what() << std::endl;
        }

        //    printing float conversion
        try {
            float f = static_cast<float>(litteral);
            std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
        }
        catch (Litteral::ImpossibleConversion const &e) {
            std::cout << "float: " << "impossible" << std::endl;
        }
        catch (std::exception const &e) {
            std::cerr << e.what() << std::endl;
        }

        //    printing double conversion
        try {
            double d = static_cast<double>(litteral);
            std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;
        }
        catch (Litteral::ImpossibleConversion const &e) {
            std::cout << "double: " << "impossible" << std::endl;
        }
        catch (std::exception const &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    catch (std::runtime_error const &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}


