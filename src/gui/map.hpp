#ifndef MAP_HPP
#define MAP_HPP

#include <vector>

#include "tile.hpp"

struct Map
{

	static const int MaxRows = 127;
	static const int MaxCols = 127;

	int rows_;
	int cols_;

	int map_tiles[ MaxRows ][ MaxCols ];
};


#endif

