#ifndef MAP_HPP
#define MAP_HPP

#include <vector>

#include "tile.hpp"

class Map
{

public:

    Map( int x, int y  )
	:  x_( x ),
	   y_( y )
	{}

	Properties::ptr Load( const std::string& fileName )
	{
		return Properties::ReadJson( fileName ); 
	}
 
    void Add( Tile& tile )
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

    std::vector< std::vector< Tile > > map_;
 
};


#endif

