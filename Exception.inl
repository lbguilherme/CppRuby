#pragma once

#include "Exception.hpp"

namespace rb
{
    
    const char* Exception::what()
    {
        return ruby_cast<char*>(inspect());
    }
    
    Object Exception::message()
    {
        return call("message");
    }
    
    Object Exception::backtrace()
    {
        return call("backtrace");
    }
    
}
