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

	typedef std::vector< char > value;
	typedef std::vector< value > data;

	void Load( const std::string& fileName )
	{
		std::string line;

		std::ifstream input;

		input.open( fileName );
		while( !input.eof() )
		{
			getline( input, line );	
		}

		input.close();
	}	

private:

	boost::shared_ptr< data >	map_;
	
};

#endif

