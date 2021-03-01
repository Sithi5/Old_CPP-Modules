#include "Pony.hpp"

void    ponyOnTheStack(){
    Pony pony_on_stack = Pony("Ponpon", "ugly green", 2, "Crushed by the stack.");
    pony_on_stack.talk();
}

void    ponyOnTheHeap(){
    Pony *pony_on_the_heap = new Pony("Heapoglicemia", "beautifull pink", 90, "Lost during a travel in the heap.");
    pony_on_the_heap->talk();
    delete pony_on_the_heap;
}

int     main(void){
    ponyOnTheStack();
    ponyOnTheHeap();
}