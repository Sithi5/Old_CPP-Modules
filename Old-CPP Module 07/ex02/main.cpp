#include "Array.tpp"

int main() {

    Array<std::string> string_array(2);
    Array<std::string> *heap_string_array = new Array<std::string>(2);

    string_array[0] = "abcd";
    string_array[1] = "efgh";

    Array<std::string> string_cpy_array(string_array);
    string_cpy_array[0] = "has been modified";
    string_cpy_array[1] = "has been modified 2";

    heap_string_array[0][0] = "ijkl";
    heap_string_array[0][1] = "mnop";

    try {
        std::cout << "String array size : " << string_array.size() << std::endl;
        std::cout << "Heap string array size : " << heap_string_array->size() << std::endl;

        std::cout << "String array content : " << std::endl;
        for (unsigned int i = 0; i < string_array.size(); i++)
            std::cout << "list[" << i << "] = " << string_array[i] << std::endl;

        std::cout << "Heap string array content : " << std::endl;
        for (unsigned int i = 0; i < heap_string_array->size(); i++)
            std::cout << "list[" << i << "] = " << heap_string_array[0][i] << std::endl;
    }
    catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }

//    Empty array
    Array<std::string> string_array_empty;

    try{
        string_array_empty[0] = "abcd";
    }
    catch (std::exception const &e) {
        std::cerr << "An error occured : " << e.what() << std::endl;
    }


    std::cout <<"TESTING CPY AND ASSIGNATION WITH INT ARRAY"  << std::endl;
//    int array
    Array<int> int_array(2);
    int_array[0] = 0;
    int_array[1] = 5;

    Array<int> cpy_int_array(int_array);
    Array<int> cpy2_int_array(2);
    Array<int> cpy3_int_array(3);
    cpy3_int_array[0] = -456;
    cpy3_int_array[1] = 4242;
    cpy3_int_array[2] = 7;
    cpy2_int_array = cpy_int_array;
    try{
        std::cout << "cpy3_int_array content : " << std::endl;
        for (unsigned int i = 0; i < cpy3_int_array.size(); i++)
            std::cout << "list[" << i << "] = " << cpy3_int_array[i] << std::endl;
        cpy3_int_array = cpy2_int_array;
    }
    catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "int_array size : " << int_array.size() << std::endl;
        std::cout << "cpy_int_array size : " << cpy_int_array.size() << std::endl;
        std::cout << "cpy2_int_array size : " << cpy2_int_array.size() << std::endl;

        std::cout << "int_array content : " << std::endl;
        for (unsigned int i = 0; i < int_array.size(); i++)
            std::cout << "list[" << i << "] = " << int_array[i] << std::endl;

        std::cout << "cpy_int_array content : " << std::endl;
        for (unsigned int i = 0; i < cpy_int_array.size(); i++)
            std::cout << "list[" << i << "] = " << cpy_int_array[i] << std::endl;

        std::cout << "cpy2_int_array content : " << std::endl;
        for (unsigned int i = 0; i < cpy2_int_array.size(); i++)
            std::cout << "list[" << i << "] = " << cpy2_int_array[i] << std::endl;

        std::cout << "cpy3_int_array content : " << std::endl;
        for (unsigned int i = 0; i < cpy3_int_array.size(); i++)
            std::cout << "list[" << i << "] = " << cpy3_int_array[i] << std::endl;


//        Testing if updating a value of a cpy will change value of original
        cpy2_int_array[0] = 999;
        cpy2_int_array[1] = -456;
        std::cout << "cpy2_int_array content : " << std::endl;
        for (unsigned int i = 0; i < cpy2_int_array.size(); i++)
            std::cout << "list[" << i << "] = " << cpy2_int_array[i] << std::endl;
        std::cout << "int_array content : " << std::endl;
        for (unsigned int i = 0; i < int_array.size(); i++)
            std::cout << "list[" << i << "] = " << int_array[i] << std::endl;
    }
    catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}