
#ifndef RUBY_CLASS_HPP
#define RUBY_CLASS_HPP

#include "Module.hpp"
#include "Identifier.hpp"
#include "helpers.hpp"

namespace rb
{
    
    class Class;
    class Class : public Module
    {
    public:
        
        Class() {}
        Class(VALUE v) {self = v; priv::ensure_kind_of(self, rb_cClass);}
        
        static Class Define(const char* name, Class super = rb_cObject);
        static Class Define(Module under, const char* name, Class super = rb_cObject);
        
        template<typename... Args>
        Object New(const Args&... args);
        
        template<Object(*Func)(Object)>
        Class& def(const char* name);
        template<Object(*Func)(Object, Object)>
        Class& def(const char* name);
        
    };
    
}

#include "Object.hpp"

#endif // RUBY_CLASS_HPP
