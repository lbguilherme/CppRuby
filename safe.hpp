#pragma once

#include "safe_impl.hpp"

namespace rb
{
    
    namespace safe
    {
        
        inline int _NUM2INT(VALUE v)
        {
            int i;
            priv::rescue<int, VALUE, _NUM2INT_impl>(&i, &v);
            return i;
        }
        
        inline VALUE _INT2NUM(int i)
        {
            VALUE v;
            priv::rescue<VALUE, int, _INT2NUM_impl>(&v, &i);
            return v;
        }
        
        inline long _NUM2LONG(VALUE v)
        {
            long l;
            priv::rescue<long, VALUE, _NUM2LONG_impl>(&l, &v);
            return l;
        }
        
        inline VALUE _LONG2NUM(long l)
        {
            VALUE v;
            priv::rescue<VALUE, long, _LONG2NUM_impl>(&v, &l);
            return v;
        }
        
        inline long long _NUM2LL(VALUE v)
        {
            long long ll;
            priv::rescue<long long, VALUE, _NUM2LL_impl>(&ll, &v);
            return ll;
        }
        
        inline VALUE _LL2NUM(long long ll)
        {
            VALUE v;
            priv::rescue<VALUE, long long, _LL2NUM_impl>(&v, &ll);
            return v;
        }
        
        inline unsigned int _NUM2UINT(VALUE v)
        {
            unsigned int ui;
            priv::rescue<unsigned int, VALUE, _NUM2UINT_impl>(&ui, &v);
            return ui;
        }
        
        inline VALUE _UINT2NUM(unsigned int ui)
        {
            VALUE v;
            priv::rescue<VALUE, unsigned int, _UINT2NUM_impl>(&v, &ui);
            return v;
        }
        
        inline unsigned long _NUM2ULONG(VALUE v)
        {
            unsigned long ul;
            priv::rescue<unsigned long, VALUE, _NUM2ULONG_impl>(&ul, &v);
            return ul;
        }
        
        inline VALUE _ULONG2NUM(unsigned long ul)
        {
            VALUE v;
            priv::rescue<VALUE, unsigned long, _ULONG2NUM_impl>(&v, &ul);
            return v;
        }
        
        inline unsigned long long _NUM2ULL(VALUE v)
        {
            unsigned long long ull;
            priv::rescue<unsigned long long, VALUE, _NUM2ULL_impl>(&ull, &v);
            return ull;
        }
        
        inline VALUE _ULL2NUM(unsigned long long ull)
        {
            VALUE v;
            priv::rescue<VALUE, unsigned long long, _ULL2NUM_impl>(&v, &ull);
            return v;
        }
        
        inline double _NUM2DBL(VALUE v)
        {
            double d;
            priv::rescue<double, VALUE, _NUM2DBL_impl>(&d, &v);
            return d;
        }
        
        inline VALUE _DBL2NUM(double d)
        {
            VALUE v;
            priv::rescue<VALUE, double, _DBL2NUM_impl>(&v, &d);
            return v;
        }
        
        inline VALUE _StringValue(VALUE v)
        {
            VALUE s;
            priv::rescue<VALUE, VALUE, _StringValue_impl>(&s, &v);
            return s;
        }
        
        inline char* _StringValuePtr(VALUE v)
        {
            char* s;
            priv::rescue<char*, VALUE, _StringValuePtr_impl>(&s, &v);
            return s;
        }
        
        inline char* _StringValueCStr(VALUE v)
        {
            char* s;
            priv::rescue<char*, VALUE, _StringValueCStr_impl>(&s, &v);
            return s;
        }
        
        inline VALUE _rb_str_new(const char* ptr, long len)
        {
            VALUE str;
            priv::rescue<VALUE, const char*, long, _rb_str_new_impl>(&str, &ptr, &len);
            return str;
        }
        
        inline VALUE _rb_funcall2(VALUE recv, ID id, int argc, VALUE* argv)
        {
            VALUE ret;
            priv::rescue<VALUE, VALUE, ID, int, VALUE*, _rb_funcall2_impl>(&ret, &recv, &id, &argc, &argv);
            return ret;
        }
        
        inline VALUE _rb_funcall3(VALUE recv, ID id, int argc, VALUE* argv)
        {
            VALUE ret;
            priv::rescue<VALUE, VALUE, ID, int, VALUE*, _rb_funcall3_impl>(&ret, &recv, &id, &argc, &argv);
            return ret;
        }
        
        inline VALUE _rb_define_module(const char* name)
        {
            VALUE mod;
            priv::rescue<VALUE, const char*, _rb_define_module_impl>(&mod, &name);
            return mod;
        }
        
        inline VALUE _rb_define_module_under(VALUE module, const char* name)
        {
            VALUE mod;
            priv::rescue<VALUE, VALUE, const char*, _rb_define_module_under_impl>(&mod, &module, &name);
            return mod;
        }
        
        template<typename... Args>
        inline VALUE _rb_sprintf(const char* format, Args... args)
        {
            VALUE str;
            priv::rescue<VALUE, const char*, Args..., _rb_sprintf_impl<Args...>>(&str, &format, &args...);
            return str;
        }
        
    }
    
}
