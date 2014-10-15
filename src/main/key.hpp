#ifndef KEY_HPP
#define KEY_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/smart_ptr.hpp>

#include "file_reader.hpp"

class Key 
{

public:

	void Load( const std::string& fileName )
	{
		std::string line;

		std::ifstream input;

		input.open( fileName );

		rows_ = 0;

		while( !input.eof() )
		{
			getline( input, line );	
			boost::shared_ptr< std::string> l = boost::make_shared< std::string >( line );
			map_.push_back( l );
			++rows_;
		}

		input.close();
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

	std::vector< boost::shared_ptr<std::string> >	keys_;

};

#endif

