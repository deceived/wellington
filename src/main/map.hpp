#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/smart_ptr.hpp>



class Map
{

public:

	static const unsigned int Rows = 128;
	static const unsigned int Columns = 128;

	void Load( const std::string& fileName )
	{
		std::string line;

		std::ifstream input;

		input.open( fileName );
		input >> rows_ >> cols_;

		unsigned int rowCount = 0;

		while( !input.eof() )
		{
			getline( input, line );	
			boost::shared_ptr< std::string> l = boost::make_shared< std::string >( line );
			map_.push_back( l );
			++rowCount;
		}

		input.close();
	}	

	boost::shared_ptr< std::string > At( unsigned int index )
	{
		return map_[ index ];
	}

	unsigned int GetRows()
	{
		return rows_;
	}

	unsigned int GetColumns()
	{
		return cols_;
	}

	boost::shared_ptr< std::string > GetRow( unsigned int index )
	{
		return map_[ index ];
	}


private:

	unsigned int rows_;
	unsigned int cols_;

	std::vector< boost::shared_ptr<std::string> >	map_;

};

#endif

