
#ifndef RUBY_MODULE_HPP
#define RUBY_MODULE_HPP

#include "Object.hpp"
#include "Identifier.hpp"

namespace rb
{
    
    class Module;
    class Module : public Object
    {
    public:
        
        Module() {}
        Module(VALUE v) : Object(v) {}
        Module(BasicObject o) : Object(o) {}
        
        static Module Define(const char* name);
        static Module Define(Module under, const char* name);
        
    };
    
}

#endif // RUBY_MODULE_HPP
