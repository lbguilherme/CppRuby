#pragma once

namespace rb
{
    
    namespace priv
    {
        // TODO: Allow method overloading
        
        template<Object(*Func)(int, Object[], Object)>
        VALUE callback(int argc, VALUE argv[], VALUE self)
        {
            Object oargs[argc]; // Valid only on GNU
            for (int i = 0; i < argc; ++i)
                oargs[i] = argv[i];
            return Func(argc, oargs, self);
        }
        
        template<Object(*Func)(Object)>
        VALUE callback(VALUE self)
        {
            return Func(self);
        }
        
        template<Object(*Func)(Object, Object)>
        VALUE callback(VALUE self, VALUE arg1)
        {
            return Func(self, arg1);
        }
        
        template<Object(*Func)(Object, Object, Object)>
        VALUE callback(VALUE self, VALUE arg1, VALUE arg2)
        {
            return Func(self, arg1, arg2);
        }
        
        template<Object(*Func)(Object, Object, Object, Object)>
        VALUE callback(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3)
        {
            return Func(self, arg1, arg2, arg3);
        }
        
        template<Object(*Func)(Object, Object, Object, Object, Object)>
        VALUE callback(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
        {
            return Func(self, arg1, arg2, arg3, arg4);
        }
        
        // TODO: Write to 15 args...
        
    }
}
