
#include "ruby.hpp"
#include <iostream>
using namespace rb;

struct A : public Object // Must inherit from Object (or, at least, from BasicObject)
{                        // This doesn't means ruby-side inheritance. Define the second
    int number;          // argument from Class::Define to do it.
    
    A() : number(0) {} // Called from #allocate
    
    Object initialize(Object num)
    {
        set_number(num);
        return self();
    }
    
    Object get_number()
    {
        return ruby_cast<Object>(number);
    }
    
    Object set_number(Object num)
    {
        number = ruby_cast<int>(num);
        return num;
    }

    Object show_all(int argc, Object argv[])
    {
        for (int i = 0; i < argc; ++i)
            std::cout << argv[i] << std::endl;
        return self();
    }
    
};

extern "C"
void Init_test()
{
    DataClass<A>::Define("A")
        .def<&A::initialize>("initialize")
        .def<&A::get_number>("number")
        .def<&A::set_number>("number=")
        .def<&A::show_all>("show_all")
    ;
}
