#include "Cato9tails.hpp"

Cato9tails::Cato9tails(void) {}

Cato9tails::~Cato9tails(void) {}


void Cato9tails::from_file(std::string file_name) {
    std::ifstream ifs;
    ifs.open(file_name.c_str());
    if (errno){
        std::cerr << "cato9tails: " << file_name << ": " << std::strerror(errno) << std::endl;
        errno = 0;
    }
    else{
        std::cout << ifs.rdbuf();
        ifs.close();
    }
}

void Cato9tails::from_stdin(void) {
    std::cout << std::cin.rdbuf();
}

