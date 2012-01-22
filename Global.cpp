
#include "Global.hpp"

namespace rb
{
    
    template<typename... Args>
    Object call(Identifier method, const Args&... args)
    {
        return Module(rb_mKernel).call(method, args...);
    }
    
    template<typename... Args>
    Object p(const Args&... args)
    {
        return call("p", args...);
    }
    
    template<typename... Args>
    Object print(const Args&... args)
    {
        return call("print", args...);
    }
    
    template<typename... Args>
    Object puts(const Args&... args)
    {
        return call("puts", args...);
    }
    
}
