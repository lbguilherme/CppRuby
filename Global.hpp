
#ifndef RUBY_GLOBAL_HPP
#define RUBY_GLOBAL_HPP

#include "Object.hpp"
#include "Class.hpp"
#include "Identifier.hpp"

namespace rb
{
    
    Class cBasicObject = rb_cBasicObject;
    Class cObject      = rb_cObject;
    Class cClass       = rb_cClass;
    
    template<typename... Args>
    static Object call(Identifier method, const Args&... args);
    
    template<typename... Args>
    static Object p(const Args&... args);
    
    template<typename... Args>
    static Object print(const Args&... args);
    
    template<typename... Args>
    static Object puts(const Args&... args);
    
}

#endif // RUBY_GLOBAL_HPP
