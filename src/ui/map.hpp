#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/smart_ptr.hpp>

#include "file_reader.hpp"


class Map
{

public:

	typedef boost::shared_ptr< std::string > line_ptr;
	typedef std::vector< line_ptr > data_type; 
	typedef boost::shared_ptr< data_type > data_ptr;

	Map()
		: map_( nullptr )
	{}

	void Load( const std::string& fileName )
	{
		map_ = FileReader::Load( fileName );
	}	

	unsigned int GetRows()
	{
		return map_->size();
	}

	unsigned int GetColumns()
	{
		return cols_;
	}

	line_ptr GetRow( unsigned int index )
	{
		return (*map_)[ index ];
	}


private:

	unsigned int rows_;
	unsigned int cols_;

	data_ptr	map_;

};

#endif

