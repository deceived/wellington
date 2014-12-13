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

    Add( Tile& tile )
    {
        map_[ tile.GetY() ][ tile.GetX() ] = tile;
    }
	
    Tile Get( int x, int y )
    {
        return map_[ y ][ x ];
    }
 
private:

    int x_;
    int y_;

    std::array< std::array< Tile, x_ >, y_ > map_;
 
};


#endif

