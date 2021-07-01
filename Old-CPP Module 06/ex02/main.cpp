#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

void identify_from_pointer(Base *p)
{

    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "failed to identify..." << std::endl;
    }
}

void identify_from_reference(Base &p)
{
    if (dynamic_cast<A *>(&p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(&p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(&p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "failed to identify..." << std::endl;
    }
}

int main(void)
{
    Base *a = new A();
    Base *b = new B();
    Base *c = new C();

    A e;
    B f;
    C g;

    std::cout << "Try identify class from pointer : " << std::endl;
    identify_from_pointer(a);
    identify_from_pointer(b);
    identify_from_pointer(c);

    std::cout << "Try identify class from reference : " << std::endl;
    identify_from_reference(*a);
    identify_from_reference(*b);
    identify_from_reference(*c);

    std::cout << "Try identify static class from reference : " << std::endl;
    identify_from_reference(e);
    identify_from_reference(f);
    identify_from_reference(g);
    delete a;
    delete b;
    delete c;
}