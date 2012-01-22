
#ifndef RUBY_CLASS_HPP
#define RUBY_CLASS_HPP

#include "Module.hpp"
#include "Identifier.hpp"

namespace rb
{
    
    class Class;
    class Class : public Module
    {
    public:
        
        Class() {}
        Class(VALUE v) : Module(v) {}
        Class(BasicObject o) : Module(o) {}
        
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
