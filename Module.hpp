
#ifndef RUBY_MODULE_HPP
#define RUBY_MODULE_HPP

#include "Object.hpp"
#include "Identifier.hpp"
#include "helpers.hpp"

namespace rb
{
    
    class Module;
    class Module : public Object
    {
    public:
        
        Module() {}
        Module(VALUE v) {self = v; priv::ensure_kind_of(self, rb_cModule);}
        
        static Module Define(const char* name);
        static Module Define(Module under, const char* name);
        
    };
    
}

#endif // RUBY_MODULE_HPP
