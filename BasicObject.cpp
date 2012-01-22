
#include "BasicObject.hpp"
#include "Object.hpp"
#include "conversions.hpp"

namespace rb
{
    
    template<typename... Args>
    BasicObject BasicObject::call(Identifier method, const Args&... args)
    {
        BasicObject oargs[] = {args...};
        return rb_funcall2(self, method.id, sizeof...(args), (VALUE*)oargs);
    }
    
    template<typename... Args>
    BasicObject BasicObject::public_call(Identifier method, const Args&... args)
    {
        BasicObject oargs[] = {args...};
        return rb_funcall3(self, method.id, sizeof...(args), (VALUE*)oargs);
    }
    
    bool operator==(BasicObject left, BasicObject right)
    {
        return left.call("==", right);
    }
    
    bool operator!=(BasicObject left, BasicObject right)
    {
        return left.call("!=", right);
    }
    
}
