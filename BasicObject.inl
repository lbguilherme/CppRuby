
#include "BasicObject.hpp"
#include "safe.hpp"

namespace rb
{
    
    template<typename... Args>
    Object BasicObject::call(Identifier method, Args... args)
    {
        BasicObject oargs[] = {args...};
        return safe::_rb_funcall2(value, method.id, sizeof...(args), reinterpret_cast<VALUE*>(oargs));
    }
    
    template<typename... Args>
    Object BasicObject::public_call(Identifier method, Args... args)
    {
        BasicObject oargs[] = {args...};
        return safe::_rb_funcall3(value, method.id, sizeof...(args), reinterpret_cast<VALUE*>(oargs));
    }
    
    Object operator==(BasicObject left, BasicObject right)
    {
        return left.call("==", right);
    }
    
    Object operator!=(BasicObject left, BasicObject right)
    {
        return left.call("!=", right);
    }
    
}
