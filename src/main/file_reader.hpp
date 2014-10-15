#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/smart_ptr.hpp>



class FileReader
{

public:

	typedef boost::shared_ptr< std::string > value;
	typedef std::vector< value > data_type;
	typedef boost::shared_ptr< data_type > data;

	void Load( const std::string& fileName )
	{
		std::string line;

		std::ifstream input;

		data lines = boost::make_shared< data_type >();

		input.open( fileName );
		while( !input.eof() )
		{
			getline( input, line );	
			boost::shared_ptr< std::string> l = boost::make_shared< std::string >( line );
			lines->push_back( l );
		}
		input.close();

		lines_ = lines;
	}	

	boost::shared_ptr< std::string > GetRow( unsigned int index )
	{
		return (*lines_)[ index ];
	}

private:

	data	lines_;

};

#endif

