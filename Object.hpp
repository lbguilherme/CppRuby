
#ifndef RUBY_OBJECT_HPP
#define RUBY_OBJECT_HPP

#include "BasicObject.hpp"
#include "Identifier.hpp"
#include "helpers.hpp"

namespace rb
{
    
    class Object;
    class Module;
    class Class;
    class Object : public BasicObject
    {
    public:
        
        Object() {}
        Object(VALUE v) {self = v; priv::ensure_kind_of(self, rb_cObject);}
        Object(BasicObject obj) : BasicObject(obj) {}
        
        Object ivar_defined(Identifier var);
        Object ivar_get(Identifier var);
        Object ivar_set(Identifier var, Object obj);
        
        Object compare(Object other);
        Object case_equal(Object other);
        Class class_of();
        Object clone();
        //Object define_singleton_method(Object name, )
        Object display(Object out = rb_stdout);
        Object dup();
        //template<typename... Args>
        //Object enum_for(Object method, const Args&... args);
        Object is_equal(Object other);
        Object is_eql(Object other);
        Object extend(Module module);
        Object freeze();
        Object is_frozen();
        Object hash();
        Object inspect();
        Object is_instance_of(Class klass);
        Object is_instance_variable_defined(Object var);
        Object instance_variable_get(Object var);
        Object instance_variable_set(Object var, Object obj);
        Object instance_variables();
        Object is_a(Module module);
        Object is_kind_of(Module module);
        Object method(Object name);
        Object methods();
        Object is_nil();
        Object object_id();
        Object public_method(Object name);
        Object public_methods();
        template<typename... Args>
        Object public_send(Object method, const Args&... args);
        Object private_method(Object name);
        Object private_methods();
        Object protected_method(Object name);
        Object protected_methods();
        Object respond_to(Object method, Object include_private = Qundef);
        Object respond_to_missing(Object method, Object include_private);
        template<typename... Args>
        Object send(Object method, const Args&... args);
        Class singleton_class();
        Object singleton_methods(Object all = Qundef);
        Object taint();
        Object is_tainted();
        Object tap(std::function<void(Object)> block);
        //template<typename... Args>
        //Object to_enum(Object method, const Args&... args);
        Object to_s();
        Object trust();
        Object untaint();
        Object untrust();
        Object is_untrusted();
        
    };
    
    std::ostream& operator<<(std::ostream& stream, Object obj);
    
    bool operator!(Object left);
    bool operator<(Object left, Object right);
    bool operator>(Object left, Object right);
    
}

#include "Class.hpp"
#include "Module.hpp"

#endif // RUBY_OBJECT_HPP
