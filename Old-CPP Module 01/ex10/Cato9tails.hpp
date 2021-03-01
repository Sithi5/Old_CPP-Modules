#ifndef TEST_CAT_HPP
#define TEST_CAT_HPP

#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>

class Cato9tails {
public:
    Cato9tails(void);
    ~Cato9tails(void);

    void from_file(std::string file_name);
    void from_stdin(void);
};


#endif //TEST_CAT_HPP
