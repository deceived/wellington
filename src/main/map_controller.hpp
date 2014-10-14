#ifndef MAP_CONTROLLER_HPP
#define MAP_CONTROLLER_HPP

#include <boost/smart_ptr.hpp>

#include "map_model.hpp"
#include "stdscr_view.hpp"

class MapController
{

public:

	MapController( boost::shared_ptr< MapModel > model )
		: model_( model )
	{}

	void LoadMap();
	void LoadKey();

	void DisplayMap();
	void DisplayKey();
	void DisplayCommand();

private:

	boost::shared_ptr< MapModel > model_;
	boost::shared_ptr< StdScrView > view_;

};

#endif

