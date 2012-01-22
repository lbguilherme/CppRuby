
#ifndef RUBY_IDENTIFIER_HPP
#define RUBY_IDENTIFIER_HPP

namespace rb
{
    
    class Identifier
    {
    public:
        
        ID id;
        
        Identifier(const char* name);
        
        Identifier(ID name);
        
        operator ID() const { return id; }
        
    };
    
}

#endif // RUBY_IDENTIFIER_HPP
