#pragma once

namespace rb
{
    
    namespace priv
    {
        // TODO: Allow method overloading
        // TODO: Write to 15 args... (now its limited to four...)
        
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
        
        template<typename T, typename Allocator = std::allocator<T>>
        void callback_free(void* ptr)
        {
            auto t_ptr = reinterpret_cast<T*>(ptr);
            t_ptr->T::~T();
            Allocator().deallocate(t_ptr, 1);
        }
        
        template<typename T, typename Allocator = std::allocator<T>>
        VALUE callback_alloc(VALUE klass)
        {
            T* obj = Allocator().allocate(1);
            new(obj) T();
            return rb_data_object_alloc(klass, obj, NULL, callback_free<T, Allocator>);
        }
        
        template<typename T, Object(T::*Func)(int, Object[])>
        VALUE callback(int argc, VALUE argv[], VALUE self)
        {
            T* obj = reinterpret_cast<T*>(DATA_PTR(self));
            obj->value = self;
            Object oargs[argc]; // Valid only on GNU
            for (int i = 0; i < argc; ++i)
                oargs[i] = argv[i];
            return (obj->*Func)(argc, oargs);
        }
        
        template<typename T, Object(T::*Func)()>
        VALUE callback(VALUE self)
        {
            T* obj = reinterpret_cast<T*>(DATA_PTR(self));
            obj->value = self;
            return (obj->*Func)();
        }
        
        template<typename T, Object(T::*Func)(Object)>
        VALUE callback(VALUE self, VALUE arg1)
        {
            T* obj = reinterpret_cast<T*>(DATA_PTR(self));
            obj->value = self;
            return (obj->*Func)(arg1);
        }
        
        template<typename T, Object(T::*Func)(Object, Object)>
        VALUE callback(VALUE self, VALUE arg1, VALUE arg2)
        {
            T* obj = reinterpret_cast<T*>(DATA_PTR(self));
            obj->value = self;
            return (obj->*Func)(arg1, arg2);
        }
        
        template<typename T, Object(T::*Func)(Object, Object, Object)>
        VALUE callback(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3)
        {
            T* obj = reinterpret_cast<T*>(DATA_PTR(self));
            obj->value = self;
            return (obj->*Func)(arg1, arg2, arg3);
        }
        
        template<typename T, Object(T::*Func)(Object, Object, Object, Object)>
        VALUE callback(VALUE self, VALUE arg1, VALUE arg2, VALUE arg3, VALUE arg4)
        {
            T* obj = reinterpret_cast<T*>(DATA_PTR(self));
            obj->value = self;
            return (obj->*Func)(arg1, arg2, arg3, arg4);
        }
        
    }
}
