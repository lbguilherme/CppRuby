
#ifndef RUBY_BASICOBJECT_HPP
#define RUBY_BASICOBJECT_HPP

#include "Identifier.hpp"

namespace rb
{
    
    class Object;
    class BasicObject;
    class BasicObject
    {
    protected:
        
        VALUE self;
        
    public:
        
        BasicObject() {};
        BasicObject(VALUE v) : self(v) {};
        
        template<typename... Args>
        BasicObject call(Identifier method, const Args&... args);
        template<typename... Args>
        BasicObject public_call(Identifier method, const Args&... args);
        
        explicit operator bool() const { return RTEST(self); }
        operator VALUE() const { return self; }
        operator RBasic*() const { return (RBasic*)self; }
        operator RString*() const { return (RString*)self; }
        
    };
    
    bool operator==(BasicObject left, BasicObject right);
    bool operator!=(BasicObject left, BasicObject right);
    
}

#endif // RUBY_BASICOBJECT_HPP
