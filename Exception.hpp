#pragma once

#include "Object.hpp"
#include "Global.hpp"
#include "conversions.hpp"

namespace rb
{
    
    class Exception : public std::exception, public Object
    {
    public:
    
        Exception() : Object(Class(rb_eException).New()) {}
        Exception(VALUE v) : Object(v) {}
        Exception(BasicObject o) : Object(o) {}
        
        template<typename... Args>
        Exception(const char* msg, Args... args) : Object(Class(rb_eException).New(safe::_rb_sprintf(msg, args...))) {}
        
        inline virtual const char* what();
        inline Object message();
        inline Object backtrace();
        
    };
    
}
