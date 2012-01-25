
#include "DataClass.hpp"
#include "Object.hpp"
#include "callback.hpp"

namespace rb
{
    
    template<typename T, typename Allocator>
    DataClass<T, Allocator> DataClass<T, Allocator>::Define(const char* name, Class super)
    {
        VALUE klass = rb_define_class(name, super);
        rb_define_alloc_func(klass, priv::callback_alloc<T, Allocator>);
        return klass;
    }
    
    template<typename T, typename Allocator>
    DataClass<T, Allocator> DataClass<T, Allocator>::Define(Module under, const char* name, Class super)
    {
        VALUE klass = rb_define_class_under(under, name, super);
        rb_define_alloc_func(klass, priv::callback_alloc<T, Allocator>);
        return klass;
    }
    
}
