#pragma once

#include "BasicObject.hpp"

namespace rb
{
    
    class Module;
    class Class;
    class Object;
    class Object : public BasicObject
    {
    public:
        
        Object() {}
        Object(VALUE v) : BasicObject(v) {}
        Object(BasicObject o) : BasicObject(o) {}
        
        Object self() {return value;}
        
        template<typename T>
        T& data() {return *reinterpret_cast<T*>(DATA_PTR(value));}
        
        inline Object ivar_defined(Identifier var);
        inline Object ivar(Identifier var);
        inline Object ivar(Identifier var, Object obj);
        
        inline Object compare(Object other);
        inline Object case_equal(Object other);
        inline Class class_of();
        inline Object clone();
        //inline Object define_singleton_method(Object name, )
        inline Object display(Object out = rb_stdout);
        inline Object dup();
        //template<typename... Args>
        //inline Object enum_for(Object method, const Args&... args);
        inline Object is_equal(Object other);
        inline Object is_eql(Object other);
        inline Object extend(Module module);
        inline Object freeze();
        inline Object is_frozen();
        inline Object hash();
        inline Object inspect();
        inline Object is_instance_of(Class klass);
        inline Object is_instance_variable_defined(Object var);
        inline Object instance_variable_get(Object var);
        inline Object instance_variable_set(Object var, Object obj);
        inline Object instance_variables();
        inline Object is_a(Module module);
        inline Object is_kind_of(Module module);
        inline Object method(Object name);
        inline Object methods();
        inline Object is_nil();
        inline Object object_id();
        inline Object public_method(Object name);
        inline Object public_methods();
        template<typename... Args>
        inline Object public_send(Object method, const Args&... args);
        inline Object private_method(Object name);
        inline Object private_methods();
        inline Object protected_method(Object name);
        inline Object protected_methods();
        inline Object respond_to(Object method, Object include_private = Qnil);
        inline Object respond_to_missing(Object method, Object include_private);
        template<typename... Args>
        inline Object send(Object method, const Args&... args);
        inline Class singleton_class();
        inline Object singleton_methods(Object all = Qtrue);
        inline Object taint();
        inline Object is_tainted();
        inline Object tap(std::function<void(Object)> block);
        //template<typename... Args>
        //inline Object to_enum(Object method, const Args&... args);
        inline Object to_s();
        inline Object trust();
        inline Object untaint();
        inline Object untrust();
        inline Object is_untrusted();
        
    };
    
    inline std::ostream& operator<<(std::ostream& stream, Object obj);
    
    inline Object operator!(Object left);
    inline Object operator<(Object left, Object right);
    inline Object operator>(Object left, Object right);
    
}
