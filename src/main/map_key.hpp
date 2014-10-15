#ifndef MAP_KEY_HPP
#define MAP_KEY_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/smart_ptr.hpp>

#include "file_reader.hpp"

class MapKey
{

public:

	void Load( const std::string& fileName )
	{
		std::string line;

		std::ifstream input;

		input.open( fileName );

		while( !input.eof() )
		{
			getline( input, line );	
			boost::shared_ptr< std::string> l = boost::make_shared< std::string >( line );
			keys_.push_back( l );
		}

		input.close();
	}	

	boost::shared_ptr< std::string > GetRow( unsigned int index )
	{
		return keys_[ index ];
	}


private:

	std::vector< boost::shared_ptr<std::string> >	keys_;

};

#endif

