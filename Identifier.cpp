
#include "Identifier.hpp"

namespace rb
{
    
    Identifier::Identifier(const char* name)
    {
        id = rb_intern(name);
    }
    
    Identifier::Identifier(ID name)
    {
        id = name;
    }
    
}
