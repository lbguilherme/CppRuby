
#include "ruby.cpp"
using namespace rb;

Object number(Object self)
{
    return convert<Object>(42);
}

extern "C"
void Init_test()
{
    Class::Define("A")
        .def<number>("number")
    ;
}
