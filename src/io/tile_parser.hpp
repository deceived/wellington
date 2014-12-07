#ifndef TILE_PARSER_HPP
#define TILE_PARSER_HPP

#include <map>
#include <vector>

#include "tile_scanner.hpp"

class Tile
{

public:

	Tile( int id )
		: id_( id )
	{}

	void AddTerrain( int terrain );
	void AddCover( int cover );

	int GetId()
	{
		return id_;
	}

	std::vector<int> GetTerrain()
	{
		return terrain_;
	}

	std::vector<int> GetCover()
	{
		return cover_;
	}

private:

	int id_;

	std::vector<int> terrain_;
	std::vector<int> cover_;

};



class TileParser
{

	typedef std::map< std::string, int > enum_type;
	typedef std::map< std::string, enum_type > enum_data;

public:

	TileParser( const std::string& fileName )
		: scanner_( fileName )
	{}

	void Parse();

private:

	TileScanner scanner_;

};

#endif

