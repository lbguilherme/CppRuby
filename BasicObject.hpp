#pragma once

#include "Identifier.hpp"

namespace rb
{
    
    class Object;
    class BasicObject;
    class BasicObject
    {
    public:
        
        VALUE value;
        
        BasicObject() {};
        BasicObject(VALUE v) : value(v) {};
        
        template<typename... Args>
        Object call(Identifier method, const Args&... args);
        template<typename... Args>
        Object public_call(Identifier method, const Args&... args);
        
        
        explicit operator bool() const { return RTEST(value); }
        operator VALUE() const { return value; }
        operator RBasic*() const { return (RBasic*)value; }
        operator RString*() const { return (RString*)value; }
        
    };
    
    bool operator==(BasicObject left, BasicObject right);
    bool operator!=(BasicObject left, BasicObject right);
    
}
