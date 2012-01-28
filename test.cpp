
#include "ruby.hpp"
#include <iostream>
using namespace rb;

struct A : public Object
{
    int number;
    
    A() : number(0) {}
    Object initialize(Object num);
    Object get_number();
    Object set_number(Object num);
    Object show_all(int argc, Object argv[]);
    Object raise_error();
    static void Init();
    
};

DataClass<A> cA;

Object A::initialize(Object num)
{
    set_number(num);
    return self();
}

Object A::get_number()
{
    return ruby_cast<Object>(number);
}

Object A::set_number(Object num)
{
    number = ruby_cast<int>(num);
    return num;
}

Object A::show_all(int argc, Object argv[])
{
    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << std::endl;
    return self();
}

Object A::raise_error()
{
    throw Exception("Error message");
}

void A::Init()
{
    cA = DataClass<A>::Define("A")
        .Public()
        .def<&A::initialize>("initialize")
        .def<&A::get_number>("number")
        .def<&A::set_number>("number=")
        .Protected()
        .def<&A::show_all>("show_all")
        .Private()
        .def<&A::raise_error>("raise_error")
    ;
}

extern "C"
void Init_test()
{
    A::Init();
}
