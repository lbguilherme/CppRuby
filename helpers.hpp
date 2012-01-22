
#ifndef RUBY_HELPERS_HPP
#define RUBY_HELPERS_HPP

#include "Object.hpp"
#include "Class.hpp"

namespace rb
{
    
    namespace priv
    {
        
        static inline void ensure_kind_of(VALUE value, VALUE klass)
        {
            if (!RTEST(rb_obj_is_kind_of(value, klass)))
                std::bad_cast();
        }
        
    }
    
}

#endif // RUBY_HELPERS_HPP

