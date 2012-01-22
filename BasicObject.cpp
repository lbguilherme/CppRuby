
#include "BasicObject.hpp"
#include "Object.hpp"
#include "conversions.hpp"
#include "helpers.hpp"

namespace rb
{
    
    template<typename T>
    BasicObject::BasicObject(const T& x, const typename std::enable_if<!std::is_base_of<BasicObject, T>::value, bool>::type)
    {
        self = convert<Object>(x);
    }
    
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
