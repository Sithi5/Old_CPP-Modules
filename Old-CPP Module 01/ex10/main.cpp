#include "Cato9tails.hpp"

int     main(int ac, char *av[]){
    Cato9tails cato0tails = Cato9tails();
    if (ac > 1){
        std::string file_name;
        for (int i = 1; i < ac; ++i){
            file_name = std::string(av[i]);
            if (!file_name.compare("-")){
                cato0tails.from_stdin();
            }
            else{
                cato0tails.from_file(av[i]);
            }
        }
    }
    else {
        cato0tails.from_stdin();
    }
    return (0);
}