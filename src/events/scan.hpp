#ifndef SCAN_HPP
#define SCAN_HPP

#include    <vector>

#include    "scan.h"

struct Symbol
{
    std::string name_;
    Tokens type_;
};

class   Symbols
{

public:

    Symbols();

    void Add( std::string& value );
    Find( Tokens token );

private:

    std::vector<Symbol> symbols_;

};

#endif
