
#ifndef RUBY_CONVERSIONS_HPP
#define RUBY_CONVERSIONS_HPP

#include "Object.hpp"

namespace rb
{
    
    template<typename To, typename From>
    static inline To convert(From x);
    
    template<> // Object -> int
    inline int convert<int>(Object x)
    {
        return NUM2INT(x);
    }
    
    template<> // int -> Object
    inline Object convert<Object>(int x)
    {
        return INT2NUM(x);
    }
    
    template<> // Object -> long
    inline long convert<long>(Object x)
    {
        return NUM2LONG(x);
    }
    
    template<> // long -> Object
    inline Object convert<Object>(long x)
    {
        return LONG2NUM(x);
    }
    
    template<> // Object -> long long
    inline long long convert<long long>(Object x)
    {
        return NUM2LL(x);
    }
    
    template<> // long long -> Object
    inline Object convert<Object>(long long x)
    {
        return LL2NUM(x);
    }
    
    template<> // Object -> unsigned int
    inline unsigned int convert<unsigned int>(Object x)
    {
        return NUM2UINT(x);
    }
    
    template<> // unsigned int -> Object
    inline Object convert<Object>(unsigned int x)
    {
        return UINT2NUM(x);
    }
    
    template<> // Object -> unsigned long
    inline unsigned long convert<unsigned long>(Object x)
    {
        return NUM2ULONG(x);
    }
    
    template<> // unsigned long -> Object
    inline Object convert<Object>(unsigned long x)
    {
        return ULONG2NUM(x);
    }
    
    template<> // Object -> unsigned long long
    inline unsigned long long convert<unsigned long long>(Object x)
    {
        return NUM2ULL(x);
    }
    
    template<> // unsigned long long -> Object
    inline Object convert<Object>(unsigned long long x)
    {
        return ULL2NUM(x);
    }
    
    template<> // Object -> float
    inline float convert<float>(Object x)
    {
        return NUM2DBL(x);
    }
    
    template<> // float -> Object
    inline Object convert<Object>(float x)
    {
        return DBL2NUM(x);
    }
    
    template<> // Object -> double
    inline double convert<double>(Object x)
    {
        return NUM2DBL(x);
    }
    
    template<> // double -> Object
    inline Object convert<Object>(double x)
    {
        return DBL2NUM(x);
    }
    
    template<> // Object -> long double
    inline long double convert<long double>(Object x)
    {
        return NUM2DBL(x);
    }
    
    template<> // long double -> Object
    inline Object convert<Object>(long double x)
    {
        return DBL2NUM(static_cast<double>(x));
    }
    
    template<> // Object -> bool
    inline bool convert<bool>(Object x)
    {
        return RTEST(x);
    }
    
    template<> // bool -> Object
    inline Object convert<Object>(bool x)
    {
        return x ? Qtrue : Qfalse;
    }
    
    template<> // Object -> char
    inline char convert<char>(Object x)
    {
        if (rb_type(x) == T_STRING)
            if (RSTRING_LEN(x) == 1)
                return RSTRING_PTR(x)[0];
            else
                throw std::invalid_argument("rb::convert<char>: string must have length 1");
        else
            return NUM2INT(x) & 0xFF;
    }
    
    template<> // char -> Object
    inline Object convert<Object>(char x)
    {
        return INT2NUM(static_cast<int>(x));
    }
    
    template<> // Object -> unsigned char
    inline unsigned char convert<unsigned char>(Object x)
    {
        if (rb_type(x) == T_STRING)
            if (RSTRING_LEN(x) == 1)
                return RSTRING_PTR(x)[0];
            else
                throw std::invalid_argument("rb::convert<unsigned char>: string must have length 1");
        else
            return NUM2INT(x) & 0xFF;
    }
    
    template<> // unsigned char -> Object
    inline Object convert<Object>(unsigned char x)
    {
        return UINT2NUM(static_cast<unsigned int>(x));
    }
    
    template<> // Object -> std::string
    inline std::string convert<std::string>(Object x)
    {
        VALUE s = x;
        StringValue(s);
        return std::string(RSTRING_PTR(s), RSTRING_PTR(s)+RSTRING_LEN(s));
    }
    
    template<> // std::string -> Object
    inline Object convert<Object>(const std::string& x)
    {
        return rb_str_new(x.data(), long(x.length()));
    }
    
}

#endif // RUBY_CONVERSIONS_HPP
