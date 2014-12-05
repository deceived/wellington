#include "tile_scan.hpp"

int TileScanner::Class( int c )
{
    if( isalpha( c ) )
    {
	return ALPHA;
    }
    if( isdigit( c ) )
    {
    	return DIGIT;
    }
    return c;
}

