#pragma once

#include "Object.hpp"
#include "Global.hpp"
#include "conversions.hpp"

namespace rb
{
    class Exception;
}

// Converts C++ exceptions to Ruby exceptions. Any object created outside the
// RBPROTECT block may not have its destructor called.

#define RBPROTECT(block) \
try block \
catch (Exception& e)             { rb_raise(rb_eException,        e.what()); } \
catch (std::bad_alloc& e)        { rb_memerror(); } \
catch (std::range_error& e)      { rb_raise(rb_eRangeError,       e.what()); } \
catch (std::overflow_error& e)   { rb_raise(rb_eRuntimeError,     e.what()); } \
catch (std::domain_error& e)     { rb_raise(rb_eFloatDomainError, e.what()); } \
catch (std::invalid_argument& e) { rb_raise(rb_eArgError,         e.what()); } \
catch (std::length_error& e)     { rb_raise(rb_eTypeError,        e.what()); } \
catch (std::out_of_range& e)     { rb_raise(rb_eRangeError,       e.what()); } \
catch (std::bad_cast& e)         { rb_raise(rb_eTypeError,        e.what()); } \
catch (std::bad_typeid& e)       { rb_raise(rb_eTypeError,        e.what()); } \
catch (std::runtime_error& e)    { rb_raise(rb_eRuntimeError,     e.what()); } \
catch (std::logic_error& e)      { rb_raise(rb_eStandardError,    e.what()); } \
catch (std::exception& e)        { rb_raise(rb_eException,        e.what()); }

namespace rb
{
    
    class Exception : public Object, public std::exception
    {
    
    public:
    
        Exception() : Object(Class(rb_eException).New()) {}
        Exception(VALUE v) : Object(v) {}
        Exception(BasicObject o) : Object(o) {}
        Exception(const char* msg) : Object(Class(rb_eException).New(ruby_cast<Object>(msg))) {}
        
        virtual const char* what() throw()
        {
            return ruby_cast<char*>(call("message"));
        }
        
    };
    
}
