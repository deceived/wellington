#ifndef MAP_HPP
#define MAP_HPP

#include <array>

#include "tile.hpp"

class Map
{

public:

    Map( int x, int y  )
	:  x_( x ),
	   y_( y )
	{}
	 
private:

    int x_;
    int y_;

    std::array< std::array< Tile, x_ >, y_ > map_;
 
};


#endif

