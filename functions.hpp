
#ifndef RUBY_FUNCTIONS_HPP
#define RUBY_FUNCTIONS_HPP

namespace rb
{
    
    namespace priv
    {
        // TODO: Add run-time checking and raise ArgumentError
        
        template<Object(*Func)(Object)>
        VALUE callback(int argc, VALUE argv[], VALUE self)
        {
            return Func(Object(self));
        }
        
        template<Object(*Func)(Object, Object)>
        VALUE callback(int argc, VALUE argv[], VALUE self)
        {
            return Func(Object(self), Object(argv[0]));
        }
        
    }
}

#endif // RUBY_FUNCTIONS_HPP
