#include "Array.tpp"

int main() {
    Array<std::string> string_array(2);
    Array<std::string> *heap_string_array = new Array<std::string>(2);

    string_array[0] = "abcd";
    string_array[1] = "efgh";

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

    Array<std::string> string_array_empty;

    try{
        string_array_empty[0] = "abcd";
    }
    catch (std::exception const &e) {
        std::cerr << "An error occured : " << e.what() << std::endl;
    }

    return 0;
}