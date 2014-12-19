#ifndef MAP_HPP
#define MAP_HPP

#include <vector>

#include "tile.hpp"

class Map
{

public:

	typedef boost::shared_ptr< std::string > line_ptr;

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

	size_t LineCount()
	{
		return map_.size();
	}

	line_ptr NextLine( size_t count )
	{
		return line_ptr();
	}
 
private:

    int x_;
    int y_;

    std::vector< std::vector< Tile > > map_;
 
};


#endif

