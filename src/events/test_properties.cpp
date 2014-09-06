#include <iostream>
#include <ostream>

#include <boost/foreach.hpp>

#include "properties.hpp"

int main( int argc, char** argv )
{
    Properties properties;

    properties.ReadXml( "ptree.xml" );
    Properties::ptr p = properties.Get();
    write_xml( std::cout, *p );

    BOOST_FOREACH( boost::property_tree::ptree::value_type &v, (*p).get_child("Actor") )
    {
        std::cout << v.second.data() << "\n";
    }

    properties.ReadJson( "ptree.json" );
    p = properties.Get();
    write_json( std::cout, *p );

    BOOST_FOREACH( boost::property_tree::ptree::value_type &v, (*p).get_child("units") )
    {
        std::cout << v.second.data() << "\n";
    }

    return 0;
}
