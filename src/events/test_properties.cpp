#include <iostream>
#include <ostream>

#include <boost/foreach.hpp>

#include "properties.hpp"

int main( int argc, char** argv )
{
    Properties properties;

    properties.ReadXml( "ptree.xml" );

    Properties::ptr pxml = properties.Get();

    write_xml( std::cout, *pxml );

    BOOST_FOREACH( boost::property_tree::ptree::value_type &v, (*pxml).get_child("Actor") )
    {
        std::cout << v.second.data() << "\n";
    }

    return 0;
}
