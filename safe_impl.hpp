#pragma once

namespace rb
{
    
    namespace safe
    {
        
        inline int _NUM2INT_impl(VALUE v)
        {
            return NUM2INT(v);
        }
        
        inline VALUE _INT2NUM_impl(int i)
        {
            return INT2NUM(i);
        }
        
        inline long _NUM2LONG_impl(VALUE v)
        {
            return NUM2LONG(v);
        }
        
        inline VALUE _LONG2NUM_impl(long l)
        {
            return LONG2NUM(l);
        }
        
        inline long long _NUM2LL_impl(VALUE v)
        {
            return NUM2LL(v);
        }
        
        inline VALUE _LL2NUM_impl(long long ll)
        {
            return LL2NUM(ll);
        }
        
        inline unsigned int _NUM2UINT_impl(VALUE v)
        {
            return NUM2UINT(v);
        }
        
        inline VALUE _UINT2NUM_impl(unsigned int ui)
        {
            return UINT2NUM(ui);
        }
        
        inline unsigned long _NUM2ULONG_impl(VALUE v)
        {
            return NUM2ULONG(v);
        }
        
        inline VALUE _ULONG2NUM_impl(unsigned long ul)
        {
            return ULONG2NUM(ul);
        }
        
        inline unsigned long long _NUM2ULL_impl(VALUE v)
        {
            return NUM2ULL(v);
        }
        
        inline VALUE _ULL2NUM_impl(unsigned long long ull)
        {
            return ULL2NUM(ull);
        }
        
        inline double _NUM2DBL_impl(VALUE v)
        {
            return NUM2DBL(v);
        }
        
        inline VALUE _DBL2NUM_impl(double d)
        {
            return DBL2NUM(d);
        }
        
        inline VALUE _StringValue_impl(VALUE v)
        {
            return StringValue(v);
        }
        
        inline char* _StringValuePtr_impl(VALUE v)
        {
            return StringValuePtr(v);
        }
        
        inline char* _StringValueCStr_impl(VALUE v)
        {
            return StringValueCStr(v);
        }
        
        inline VALUE _rb_str_new_impl(const char* ptr, long len)
        {
            return rb_str_new(ptr, len);
        }
        
        inline VALUE _rb_funcall2_impl(VALUE recv, ID id, int argc, VALUE* argv)
        {
            return rb_funcall2(recv, id, argc, argv);
        }
        
        inline VALUE _rb_funcall3_impl(VALUE recv, ID id, int argc, VALUE* argv)
        {
            return rb_funcall3(recv, id, argc, argv);
        }
        
        inline VALUE _rb_define_module_impl(const char* name)
        {
            return rb_define_module(name);
        }
        
        inline VALUE _rb_define_module_under_impl(VALUE module, const char* name)
        {
            return rb_define_module_under(module, name);
        }
        
        template<typename... Args>
        inline VALUE _rb_sprintf_impl(const char* format, Args... args)
        {
            return rb_sprintf(format, args...);
        }
        
    }
    
}
