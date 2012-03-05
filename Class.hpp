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
        
        inline static Class Define(const char* name, Class super = rb_cObject);
        inline static Class Define(Module under, const char* name, Class super = rb_cObject);
        
        template<typename... Args>
        inline Object New(Args... args);
        
        Class& Public()    {m_method_visibility = PUBLIC;    return *this;}
        Class& Protected() {m_method_visibility = PROTECTED; return *this;}
        Class& Private()   {m_method_visibility = PRIVATE;   return *this;}
        
        template<typename... Args>
        inline Class& Public(const char* name);
        template<typename... Args>
        inline Class& Public(const char* name, const char* name2, const Args&... args);
        
        template<typename... Args>
        inline Class& Protected(const char* name);
        template<typename... Args>
        inline Class& Protected(const char* name, const char* name2, const Args&... args);
        
        template<typename... Args>
        inline Class& Private(const char* name);
        template<typename... Args>
        inline Class& Private(const char* name, const char* name2, const Args&... args);
        
        template<Object(*Func)(int, Object[], Object)>
        inline Class& def(const char* name);
        template<Object(*Func)(Object)>
        inline Class& def(const char* name);
        template<Object(*Func)(Object, Object)>
        inline Class& def(const char* name);
        template<Object(*Func)(Object, Object, Object)>
        inline Class& def(const char* name);
        template<Object(*Func)(Object, Object, Object, Object)>
        inline Class& def(const char* name);
        template<Object(*Func)(Object, Object, Object, Object, Object)>
        inline Class& def(const char* name);
        
    };
    
}
