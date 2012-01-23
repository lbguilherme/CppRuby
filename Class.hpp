#pragma once

#include "Module.hpp"
#include "callback.hpp"

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
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, -1); return *this; }
        
        template<Object(*Func)(Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 0); return *this; }
        
        template<Object(*Func)(Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 1); return *this; }
        
        template<Object(*Func)(Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 2); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 3); return *this; }
        /*
        template<Object(*Func)(Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 4); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 5); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 6); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 7); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 8); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 9); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 10); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 11); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 12); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 13); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 14); return *this; }
        
        template<Object(*Func)(Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object, Object)>
        Class& def(const char* name)
        {auto f = priv::callback<Func>; rb_define_method(value, name, (VALUE(*)(...))f, 15); return *this; }
        */
    };
    
}
