#pragma once

namespace rb
{
    
    class Exception;
    
    namespace priv
    {
        
        VALUE rescue_rescue_block(VALUE data, VALUE ex)
        {
            VALUE* out = (VALUE*)data;
            *out = ex;
            return Qnil;
        }
        
        template<typename RetT, RetT(*Func)()>
        VALUE rescue_begin_body(VALUE data)
        {
            void** ptr = (void**)data;
            RetT* out = reinterpret_cast<RetT*>(ptr[0]);
            *out = Func();
            return Qnil;
        }
        
        template<typename RetT, typename Arg1T, RetT(*Func)(Arg1T)>
        VALUE rescue_begin_body(VALUE data)
        {
            void** ptr = (void**)data;
            RetT* out = reinterpret_cast<RetT*>(ptr[0]);
            Arg1T* arg1 = reinterpret_cast<Arg1T*>(ptr[1]);
            *out = Func(*arg1);
            return Qnil;
        }
        
        template<typename RetT, RetT(*Func)()>
        void rescue(RetT* out)
        {
            auto f1 = rescue_begin_body<RetT, Func>;
            auto f2 = rescue_rescue_block;
            void* data[1];
            data[0] = reinterpret_cast<void*>(out);
            VALUE ex = Qnil;
            rb_rescue2((VALUE(*)(...))f1, (VALUE)data, (VALUE(*)(...))f2, (VALUE)&ex, rb_eException, 0);
            if (ex != Qnil)
                throw Exception(ex);
        }
            
        template<typename RetT, typename Arg1T, RetT(*Func)(Arg1T)>
        void rescue(RetT* out, Arg1T* arg1)
        {
            auto f1 = rescue_begin_body<RetT, Arg1T, Func>;
            auto f2 = rescue_rescue_block;
            void* data[2];
            data[0] = reinterpret_cast<void*>(out);
            data[1] = reinterpret_cast<void*>(arg1);
            VALUE ex = Qnil;
            rb_rescue2((VALUE(*)(...))f1, (VALUE)data, (VALUE(*)(...))f2, (VALUE)&ex, rb_eException, 0);
            if (ex != Qnil)
                throw Exception(ex);
        }
        
    }
}
