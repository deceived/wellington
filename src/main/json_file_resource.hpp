#ifndef JSON_FILE_RESOURCE_HPP
#define JSON_FILE_RESOURCE_HPP

#include "resource.hpp"
#include "properties.hpp"

class JsonFileResource : public Resource
{

public:

	JsonFileResource( std::string& fileName )
		: 	fileName_( fileName ),
			resource_( nullptr )
	{}

	void Load()
	{
		resource_ = Properties::ReadJson( fileName_ );
	}

private:

	std::string fileName_;

	Properties::ptr resource_;

};

#endif

