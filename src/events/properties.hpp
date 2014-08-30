#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#include <string>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class Properties
{

public:

    Properties( const std::string& filename )
        : fileName_( filename )
    {
        properties_ = boost::make_shared< boost::property_tree::ptree >();

        read_json( fileName_, *properties_ );        
    }

    boost::shared_ptr< boost::property_tree::ptree > Get()
    {
        return properties_;
    }

private:

    std::string fileName_;

    boost::shared_ptr< boost::property_tree::ptree > properties_;

};

#endif

