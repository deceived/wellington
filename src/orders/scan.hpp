#ifndef SCAN_HPP
#define SCAN_HPP

#include    <boost/smart_ptr.hpp>

#include    <vector>

#include    "scan.h"



struct Symbol
{
    std::string name_;
    Token_t type_;
};

struct Direction : public Symbol
{
};

struct UnitSpecification : public Symbol
{
    unsigned int unitNumber_;
    std::vector<std::string> name_;
};

struct Word : Symbol
{
    std::vector<std::string> name_;
};



class   Symbols
{

public:

    Symbols();

    void Add( boost::shared_ptr<Symbol>& symbol );
    boost::shared_ptr<Symbol> Find( Token_t token );

private:

    std::vector< boost::shared_ptr<Symbol> > symbols_;

};

#endif
