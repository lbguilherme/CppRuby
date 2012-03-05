#pragma once

#include "Object.hpp"
#include "Identifier.hpp"

namespace rb
{
    
    class Module;
    class Module : public Object
    {
    protected:
        
        enum {PUBLIC, PROTECTED, PRIVATE, MODULE_FUNCTION} m_method_visibility;
        
    public:
        
        Module() : m_method_visibility(PUBLIC) {}
        Module(VALUE v) : Object(v), m_method_visibility(PUBLIC) {}
        Module(BasicObject o) : Object(o), m_method_visibility(PUBLIC) {}
        
        inline static Module Define(const char* name);
        inline static Module Define(Module under, const char* name);
        
        Module& Public()          {m_method_visibility = PUBLIC;          return *this;}
        Module& Protected()       {m_method_visibility = PROTECTED;       return *this;}
        Module& Private()         {m_method_visibility = PRIVATE;         return *this;}
        Module& module_function() {m_method_visibility = MODULE_FUNCTION; return *this;}
        
        template<typename... Args>
        inline Module& Public(const char* name);
        template<typename... Args>
        inline Module& Public(const char* name, const char* name2, const Args&... args);
        
        template<typename... Args>
        inline Module& Protected(const char* name);
        template<typename... Args>
        inline Module& Protected(const char* name, const char* name2, const Args&... args);
        
        template<typename... Args>
        inline Module& Private(const char* name);
        template<typename... Args>
        inline Module& Private(const char* name, const char* name2, const Args&... args);
        
        template<typename... Args>
        inline Module& module_function(const char* name);
        template<typename... Args>
        inline Module& module_function(const char* name, const char* name2, const Args&... args);
        
        template<Object(*Func)(int, Object[], Object)>
        inline Module& def(const char* name);
        template<Object(*Func)(Object)>
        inline Module& def(const char* name);
        template<Object(*Func)(Object, Object)>
        inline Module& def(const char* name);
        template<Object(*Func)(Object, Object, Object)>
        inline Module& def(const char* name);
        template<Object(*Func)(Object, Object, Object, Object)>
        inline Module& def(const char* name);
        template<Object(*Func)(Object, Object, Object, Object, Object)>
        inline Module& def(const char* name);
        
    };
    
}
