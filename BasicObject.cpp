
#include "BasicObject.hpp"

namespace rb
{
    
    template<typename... Args>
    Object BasicObject::call(Identifier method, const Args&... args)
    {
        BasicObject oargs[] = {args...};
        return rb_funcall2(value, method.id, sizeof...(args), (VALUE*)oargs);
    }
    
    template<typename... Args>
    Object BasicObject::public_call(Identifier method, const Args&... args)
    {
        BasicObject oargs[] = {args...};
        return rb_funcall3(value, method.id, sizeof...(args), (VALUE*)oargs);
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
