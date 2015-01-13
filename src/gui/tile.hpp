#ifndef TILE_HPP
#define TILE_HPP

#include <vector>

#include <boost/smart_ptr.hpp>


struct Tile
{

    unsigned int id_;

    unsigned int terrain_;
	char terrain_representation_;

	std::vector<unsigned int > cover_;

};

#endif
