#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <string>

#include "properties.hpp"

class Resource
{

public:

	Resource( std::string& name )
		: name_( name )
	{}

private:

	std::string name_;

};

class JsonFileResource : public Resource
{

public:

	FileResource( std::string& fileName )
		: fileName_( fileName )
	{}

	void Load()
	{
	}

private:

	std::string fileName_;

};

#endif

