
#include "Global.hpp"

namespace rb
{
    
    template<typename... Args>
    Object p(Args... args)
    {
        return mKernel.call("p", args...);
    }
    
    template<typename... Args>
    Object print(Args... args)
    {
        return mKernel.call("print", args...);
    }
    
    template<typename... Args>
    Object puts(Args... args)
    {
        return mKernel.call("puts", args...);
    }
    
    template<typename... Args>
    Object raise(Args... args)
    {
        return mKernel.call("raise", args...);
    }
    
}
