#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#include <string>

#include <boost/smart_ptr.hpp>

#include <boost/property_tree/ptree.hpp>

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include "pugixml.hpp"



class Properties
{

public:

    typedef boost::property_tree::ptree property_tree;
    typedef boost::shared_ptr< property_tree > ptr;

    typedef pugi::xml_document data_type;
    typedef boost::shared_ptr< data_type > pointer; 

    static pointer ReadXmlDoc( const std::string& fileName )
    {
        pointer doc = boost::make_shared< pugi::xml_document >();
        pugi::xml_parse_result result = doc->load_file( fileName.c_str() );
        return doc;
    }

    static ptr ReadXml( const std::string& fileName )
    {
        ptr properties = boost::make_shared< property_tree >();
        read_xml( fileName, *properties );        
        return properties;
    }

    static ptr ReadJson( const std::string& fileName )
    {
        ptr properties = boost::make_shared< property_tree >();
        read_json( fileName, *properties );        
        return properties;
    }

    static ptr ReadIni( const std::string& fileName )
    {
        ptr properties = boost::make_shared< property_tree >();
        read_json( fileName, *properties );        
        return properties;
    }

};



#endif