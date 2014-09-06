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
        std::cout << v.first << "\n";
    }

    properties.ReadJson( "ptree.json" );
    p = properties.Get();
    write_json( std::cout, *p );

    BOOST_FOREACH( boost::property_tree::ptree::value_type &v, (*p).get_child("units") )
    {
        std::cout << v.first << "\n";
        BOOST_FOREACH( boost::property_tree::ptree::value_type &vc, v.second )
        {
            std::cout << vc.first << "\n";
            BOOST_FOREACH( boost::property_tree::ptree::value_type &vcc, vc.second )
            {
                std::cout << vcc.first <<  " " << vcc.second.data() << "\n";
            } 
        } 
    }

    return 0;
}
