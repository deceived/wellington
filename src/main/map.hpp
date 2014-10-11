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

private:

	unsigned int rows_;
	unsigned int cols_;

	std::vector< boost::shared_ptr<std::string> >	map_;

};

#endif

