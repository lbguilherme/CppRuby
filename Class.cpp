
#include "Class.hpp"
#include "helpers.hpp"
#include "functions.hpp"

namespace rb
{
    
    Class Class::Define(const char* name, Class super)
    {
        return rb_define_class(name, super);
    }
    
    Class Class::Define(Module under, const char* name, Class super)
    {
        return rb_define_class_under(under, name, super);
    }
    
    template<typename... Args>
    Object Class::New(const Args&... args)
    {
        return rb_class_new_instance(sizeof...(args), (VALUE[]){args...}, self);
    }
    
    template<Object(*Func)(Object)>
    Class& Class::def(const char* name)
    {
        auto f = priv::callback<Func>;
        rb_define_method(self, name, (VALUE(*)(...))f, -1);
        return *this;
    }
    
    template<Object(*Func)(Object, Object)>
    Class& Class::def(const char* name)
    {
        auto f = priv::callback<Func>;
        rb_define_method(self, name, (VALUE(*)(...))f, -1);
        return *this;
    }
    
}
