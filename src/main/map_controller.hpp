#ifndef MAP_CONTROLLER_HPP
#define MAP_CONTROLLER_HPP

#include <boost/smart_ptr.hpp>

#include "map_model.hpp"

class MapController
{

public:

	MapController( boost::shared_ptr< MapModel > model )
		: model_( model )
	{}

private:

	void LoadMap();
	void LoadKey();

	boost::shared_ptr< MapModel > model_;

};

#endif

