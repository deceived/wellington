#ifndef MAP_MODEL_HPP
#define MAP_MODEL_HPP

#include <string>

#include <boost/smart_ptr.hpp>

class MapModel
{

public:

	typedef boost::shared_ptr< Map >	map_ptr;

	MapModel()
	{}

	map_ptr	GetMap();

	void Load( std::string fileName );

private:

	map_ptr		map_;
};

#endif

