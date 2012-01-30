#pragma once

#include "Object.hpp"
#include "Exception_rescue.hpp"

namespace rb
{
    
    template<typename To, typename From>
    To ruby_cast_impl(From x);
    
    template<typename To, typename From>
    To ruby_cast(From x)
    {
        To out;
        priv::rescue<To, From, ruby_cast_impl<To, From>>(&out, &x);
        return out;
    }
    
    template<> // Object -> Class
    Class ruby_cast_impl<Class>(Object x)
    {
        if (x.is_kind_of(cClass))
            return x;
        else
            throw std::bad_cast();
    }
    
    template<> // Object -> int
    int ruby_cast_impl<int>(Object x)
    {
        return NUM2INT(x);
    }
    
    template<> // int -> Object
    Object ruby_cast_impl<Object>(int x)
    {
        return INT2NUM(x);
    }
    
    template<> // Object -> long
    long ruby_cast_impl<long>(Object x)
    {
        return NUM2LONG(x);
    }
    
    template<> // long -> Object
    Object ruby_cast_impl<Object>(long x)
    {
        return LONG2NUM(x);
    }
    
    template<> // Object -> long long
    long long ruby_cast_impl<long long>(Object x)
    {
        return NUM2LL(x);
    }
    
    template<> // long long -> Object
    Object ruby_cast_impl<Object>(long long x)
    {
        return LL2NUM(x);
    }
    
    template<> // Object -> unsigned int
    unsigned int ruby_cast_impl<unsigned int>(Object x)
    {
        return NUM2UINT(x);
    }
    
    template<> // unsigned int -> Object
    Object ruby_cast_impl<Object>(unsigned int x)
    {
        return UINT2NUM(x);
    }
    
    template<> // Object -> unsigned long
    unsigned long ruby_cast_impl<unsigned long>(Object x)
    {
        return NUM2ULONG(x);
    }
    
    template<> // unsigned long -> Object
    Object ruby_cast_impl<Object>(unsigned long x)
    {
        return ULONG2NUM(x);
    }
    
    template<> // Object -> unsigned long long
    unsigned long long ruby_cast_impl<unsigned long long>(Object x)
    {
        return NUM2ULL(x);
    }
    
    template<> // unsigned long long -> Object
    Object ruby_cast_impl<Object>(unsigned long long x)
    {
        return ULL2NUM(x);
    }
    
    template<> // Object -> float
    float ruby_cast_impl<float>(Object x)
    {
        return NUM2DBL(x);
    }
    
    template<> // float -> Object
    Object ruby_cast_impl<Object>(float x)
    {
        return DBL2NUM(x);
    }
    
    template<> // Object -> double
    double ruby_cast_impl<double>(Object x)
    {
        return NUM2DBL(x);
    }
    
    template<> // double -> Object
    Object ruby_cast_impl<Object>(double x)
    {
        return DBL2NUM(x);
    }
    
    template<> // Object -> long double
    long double ruby_cast_impl<long double>(Object x)
    {
        return NUM2DBL(x);
    }
    
    template<> // long double -> Object
    Object ruby_cast_impl<Object>(long double x)
    {
        return DBL2NUM(static_cast<double>(x));
    }
    
    template<> // Object -> bool
    bool ruby_cast_impl<bool>(Object x)
    {
        return RTEST(x);
    }
    
    template<> // bool -> Object
    Object ruby_cast_impl<Object>(bool x)
    {
        return x ? Qtrue : Qfalse;
    }
    
    template<> // Object -> char
    char ruby_cast_impl<char>(Object x)
    {
        if (rb_type(x) == T_STRING)
            if (RSTRING_LEN(x) == 1)
                return RSTRING_PTR(x)[0];
            else
                throw std::invalid_argument("rb::ruby_cast_impl<char>: string must have length 1");
        else
            return NUM2INT(x);
    }
    
    template<> // char -> Object
    Object ruby_cast_impl<Object>(char x)
    {
        return INT2NUM(static_cast<int>(x));
    }
    
    template<> // Object -> unsigned char
    unsigned char ruby_cast_impl<unsigned char>(Object x)
    {
        if (rb_type(x) == T_STRING)
            if (RSTRING_LEN(x) == 1)
                return RSTRING_PTR(x)[0];
            else
                throw std::invalid_argument("rb::ruby_cast_impl<unsigned char>: string must have length 1");
        else
            return NUM2INT(x);
    }
    
    template<> // unsigned char -> Object
    Object ruby_cast_impl<Object>(unsigned char x)
    {
        return UINT2NUM(static_cast<unsigned int>(x));
    }
    
    template<> // Object -> char*
    char* ruby_cast_impl<char*>(Object x)
    {
        VALUE s = x;
        return StringValueCStr(s);
    }
    
    template<> // char* -> Object
    Object ruby_cast_impl<Object>(const char* x)
    {
        return rb_str_new(x, strlen(x));
    }
    
    template<> // Object -> std::string
    std::string ruby_cast_impl<std::string>(Object x)
    {
        VALUE s = x;
        StringValue(s);
        return std::string(RSTRING_PTR(s), RSTRING_PTR(s)+RSTRING_LEN(s));
    }
    
    template<> // std::string -> Object
    Object ruby_cast_impl<Object>(const std::string& x)
    {
        return rb_str_new(x.data(), long(x.length()));
    }
    
}
