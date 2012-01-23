
#include "ruby.hpp"
#include <iostream>
using namespace rb;

Object A_get_number(Object self)
{
    if (self.ivar("@number") == Nil)
        return ruby_cast<Object>(0);
    
    return self.ivar("@number");
}

Object A_set_number(Object self, Object number)
{
    self.ivar("@number", number);
    return number;
}

Object A_show_all(int argc, Object argv[], Object self)
{
    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << std::endl; // calls #to_s
    return self;
}

extern "C"
void Init_test()
{
    Class::Define("A")
        .def<A_get_number>("number")
        .def<A_set_number>("number=")
        .def<A_show_all>("show_all")
    ;
}
