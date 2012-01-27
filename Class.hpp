#pragma once

#include "Module.hpp"

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
    
        template<Object(*Func)(int, Object[], Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object)>
        Class& def(const char* name);
        /*
        template<Object(*Func)(Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name);
        */
    };
    
}
