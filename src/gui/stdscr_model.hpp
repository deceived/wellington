#ifndef STDSCR_MODEL_HPP
#define STDSCR_MODEL_HPP

#include "map.hpp"
#include "key.hpp"
#include "cmd.hpp"

class StdScrModel
{

public:

	typedef boost::shared_ptr< std::string > line_ptr;

	StdScrModel()
	{}

	void LoadMap( const std::string& fileName )
	{
		map_->Load( fileName );
	}

	void LoadKey( const std::string& fileName )
	{
		key_->Load( fileName );
	}

	void LoadCmd( )
	{
	}

	line_ptr  GetPrompt();
	line_ptr NextLine( size_t line );
	map_ptr	GetMap();

private:

};

#endif

