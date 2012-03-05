#pragma once

#include "Exception_protect.hpp"

namespace rb
{
    
    namespace priv
    {
        
        template<Object(*Func)(int, Object[], Object)>
        inline VALUE callback(int argc, VALUE argv[], VALUE self)
        {
            RBPROTECT
            ({
                return Func(argc, reinterpret_cast<Object*>(argv), self);
            })
            return Nil;
        }
        
        template<Object(*Func)(Object)>
        inline VALUE callback(VALUE self)
        {
            RBPROTECT
            ({
                return Func(self);
            })
            return Nil;
        }
        
        template<Object(*Func)(Object, Object)>
        inline VALUE callback(VALUE self, VALUE arg1)
        {
            RBPROTECT
            ({
                return Func(self, arg1);
            })
            return Nil;
        }
        
        template<Object(*Func)(Object, Object, Object)>
        inline VALUE callback(VALUE self, VALUE arg1, VALUE arg2)
        {
            RBPROTECT
            ({
                return Func(self, arg1, arg2);
            })
            return Nil;
        }
        
        template<Object(*Func)(Object, Object, Object, Object)>
        inline VALUE callback(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3)
        {
            RBPROTECT
            ({
                return Func(self, arg1, arg2, arg3);
            })
            return Nil;
        }
        
        template<Object(*Func)(Object, Object, Object, Object, Object)>
        inline VALUE callback(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
        {
            RBPROTECT
            ({
                return Func(self, arg1, arg2, arg3, arg4);
            })
            return Nil;
        }
        
    }
    
}
