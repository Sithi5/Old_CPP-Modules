#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

std::string replace(std::string file_text, std::string search, std::string replace){
    int occurence_pos = 0;
    int len_search = search.length();
    int len_replace = replace.length();

    if (search.empty() || replace.empty()){
        throw std::runtime_error("replace or search should not be empty.");
    }
    while ((const size_t)(occurence_pos = file_text.find(search, occurence_pos)) != std::string::npos){
        file_text.erase(occurence_pos, len_search);
        file_text.insert(occurence_pos, replace);
        if (len_replace > 0){
            occurence_pos += len_replace;
        }
        else{
            occurence_pos ++;
        }
    }
    return file_text + "\n";
}

int     main(int ac, char **av)
{
    if (ac != 4){
        std::cout << "Invalid number of arguments. Must be exactly 3." << std::endl;
    }
    else{
        try{
            std::ifstream ifs(av[1]);
            std::ofstream ofs((std::string(av[1]) + ".replace").c_str());
            if (!ifs.is_open() || !ofs.is_open()) {
                throw std::runtime_error("error when opening a file.");
            }
            if (strcmp(av[2], "") == 0 || strcmp(av[3], "") == 0){
                throw std::runtime_error("replace or search argument should not be empty.");
            }

            std::stringstream buffer;

            buffer << ifs.rdbuf();
            ifs.close();
            ofs << replace(buffer.str(), av[2], av[3]);
            ofs.close();

        }
        catch (std::exception &error){
            std::cerr << error.what() << std::endl;
        }
    }
    return (0);
}
