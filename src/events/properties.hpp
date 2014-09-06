#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#include <string>

#include <boost/smart_ptr.hpp>

#include <boost/property_tree/ptree.hpp>

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>


class Properties
{

public:

    typedef boost::property_tree::ptree property_tree;
    typedef boost::shared_ptr< property_tree > ptr;

    Properties()
        : properties_( boost::make_shared< property_tree >() )
    { std::cout << "ctor()"; }
 
    void ReadXml( const std::string& fileName )
    {
        read_xml( fileName, *properties_ );        
    }

    void ReadJson( const std::string& fileName )
    {
        read_json( fileName, *properties_ );        
    }

    void ReadIni( const std::string& fileName )
    {
        read_json( fileName, *properties_ );        
    }

    ptr Get()
    {
        return properties_;
    }

private:

    ptr properties_;

};

#endif

