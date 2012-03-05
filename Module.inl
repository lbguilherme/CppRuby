
#include "Module.hpp"
#include "safe.hpp"

namespace rb
{
    
    Module Module::Define(const char* name)
    {
        return safe::_rb_define_module(name);
    }
    
    Module Module::Define(Module under, const char* name)
    {
        return safe::_rb_define_module_under(under, name);
    }
    
    template<typename... Args>
    Module& Module::Public(const char* name)
    {
        call("public", ruby_cast<Object>(name));
        return *this;
    }
    
    template<typename... Args>
    Module& Module::Public(const char* name, const char* name2, const Args&... args)
    {
        Public(name);
        return Public(name2, args...);
    }
    
    template<typename... Args>
    Module& Module::Protected(const char* name)
    {
        call("protected", ruby_cast<Object>(name));
        return *this;
    }
    
    template<typename... Args>
    Module& Module::Protected(const char* name, const char* name2, const Args&... args)
    {
        Protected(name);
        return Protected(name2, args...);
    }
    
    template<typename... Args>
    Module& Module::Private(const char* name)
    {
        call("private", ruby_cast<Object>(name));
        return *this;
    }
    
    template<typename... Args>
    Module& Module::Private(const char* name, const char* name2, const Args&... args)
    {
        Private(name);
        return Private(name2, args...);
    }
    
    template<typename... Args>
    Module& Module::module_function(const char* name)
    {
        call("module_function", ruby_cast<Object>(name));
        return *this;
    }
    
    template<typename... Args>
    Module& Module::module_function(const char* name, const char* name2, const Args&... args)
    {
        module_function(name);
        return module_function(name2, args...);
    }
    
#define define_method(func, name, argc) \
    switch (m_method_visibility) \
    { \
        case PUBLIC:          rb_define_method          (value, name, func, argc); break; \
        case PROTECTED:       rb_define_protected_method(value, name, func, argc); break; \
        case PRIVATE:         rb_define_private_method  (value, name, func, argc); break; \
        case MODULE_FUNCTION: rb_define_module_function (value, name, func, argc); break; \
    }
    
    template<Object(*Func)(int, Object[], Object)>
    Module& Module::def(const char* name)
    {
        auto f = priv::callback<Func>;
        define_method((VALUE(*)(...))f, name, -1);
        return *this;
    }
    
    template<Object(*Func)(Object)>
    Module& Module::def(const char* name)
    {
        auto f = priv::callback<Func>;
        define_method((VALUE(*)(...))f, name, 0);
        return *this;
    }
    
    template<Object(*Func)(Object, Object)>
    Module& Module::def(const char* name)
    {
        auto f = priv::callback<Func>;
        define_method((VALUE(*)(...))f, name, 1);
        return *this;
    }
    
    template<Object(*Func)(Object, Object, Object)>
    Module& Module::def(const char* name)
    {
        auto f = priv::callback<Func>;
        define_method((VALUE(*)(...))f, name, 2);
        return *this;
    }
    
    template<Object(*Func)(Object, Object, Object, Object)>
    Module& Module::def(const char* name)
    {
        auto f = priv::callback<Func>;
        define_method((VALUE(*)(...))f, name, 3);
        return *this;
    }
    
    template<Object(*Func)(Object, Object, Object, Object, Object)>
    Module& Module::def(const char* name)
    {
        auto f = priv::callback<Func>;
        define_method((VALUE(*)(...))f, name, 4);
        return *this;
    }
    
#undef define_method
    
}
