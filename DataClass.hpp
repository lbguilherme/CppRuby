#pragma once

#include "Module.hpp"
#include "callback.hpp"

namespace rb
{
    template<typename T, typename Allocator = std::allocator<T>>
    class DataClass;
    template<typename T, typename Allocator>
    class DataClass : public Module
    {
    public:
        
        DataClass() {}
        DataClass(VALUE v) : Module(v) {}
        DataClass(BasicObject o) : Module(o) {}
        
        static DataClass<T, Allocator> Define(const char* name, Class super = rb_cObject);
        static DataClass<T, Allocator> Define(Module under, const char* name, Class super = rb_cObject);
        
        template<typename... Args>
        Object New(const Args&... args)
        {
            return rb_class_new_instance(sizeof...(args), (VALUE[]){args...}, value);
        }
        
        template<Object(T::*Func)(int, Object[])>
        DataClass<T, Allocator>& def(const char* name)
        {
            auto f = priv::callback<T, Func>;
            rb_define_method(value, name, (VALUE(*)(...))f, -1);
            return *this;
        }
        
        template<Object(T::*Func)()>
        DataClass<T, Allocator>& def(const char* name)
        {
            auto f = priv::callback<T, Func>;
            rb_define_method(value, name, (VALUE(*)(...))f, 0);
            return *this;
        }
        
        template<Object(T::*Func)(Object)>
        DataClass<T, Allocator>& def(const char* name)
        {
            auto f = priv::callback<T, Func>;
            rb_define_method(value, name, (VALUE(*)(...))f, 1);
            return *this;
        }
        
        template<Object(T::*Func)(Object, Object)>
        DataClass<T, Allocator>& def(const char* name)
        {
            auto f = priv::callback<T, Func>;
            rb_define_method(value, name, (VALUE(*)(...))f, 2);
            return *this;
        }
        
        template<Object(T::*Func)(Object, Object, Object)>
        DataClass<T, Allocator>& def(const char* name)
        {
            auto f = priv::callback<T, Func>;
            rb_define_method(value, name, (VALUE(*)(...))f, 3);
            return *this;
        }
        
        template<Object(T::*Func)(Object, Object, Object, Object)>
        DataClass<T, Allocator>& def(const char* name)
        {
            auto f = priv::callback<T, Func>;
            rb_define_method(value, name, (VALUE(*)(...))f, 4);
            return *this;
        }
        
    };
    
}
