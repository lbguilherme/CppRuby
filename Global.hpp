#pragma once

#include "Object.hpp"
#include "Class.hpp"
#include "Identifier.hpp"

namespace rb
{
    
    Module mKernel     = rb_mKernel;
    
    Class cBasicObject = rb_cBasicObject;
    Class cObject      = rb_cObject;
    Class cClass       = rb_cClass;
    
    Class eException   = rb_eException;
    
    Object Nil   = Qnil;
    Object True  = Qtrue;
    Object False = Qfalse;
    Object Undef = Qundef;
    
    template<typename... Args>
    Object call(Identifier method, const Args&... args);
    
    template<typename... Args>
    Object p(const Args&... args);
    
    template<typename... Args>
    Object print(const Args&... args);
    
    template<typename... Args>
    Object puts(const Args&... args);
    
}
