#include <iostream>
#include <stdlib.h>
#include <time.h>

struct Data { std::string s1; int n; std::string s2; };

void * serialize(void){
    srand(time(NULL));
    Data *data = new Data();
    data->s1 = "test123";
    data->n = rand();
    data->s2 = "123test";

    return static_cast<void *>(data);
}

Data * deserialize(void * raw){
    return static_cast<Data *>(raw);
}

int main(void){
    void *raw = serialize();
    Data *data = deserialize(raw);
    std::cout << "first string is : "<< data->s1 << " random n is : " << data->n << " second string is : " <<data->s2 << std::endl;
    return 0;
}