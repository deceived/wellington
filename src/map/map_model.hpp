#ifndef MAP_MODEL_HPP
#define MAP_MODEL_HPP

#include "properties.hpp"

class MapModel
{

public:

	void Load( const std::string& fileName )
	{
		model_ = Properties::ReadJson( fileName );
	}

private:

	Properties::ptr model_;
};

#endif

