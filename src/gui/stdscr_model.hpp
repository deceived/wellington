#ifndef STDSCR_MODEL_HPP
#define STDSCR_MODEL_HPP

#include <boost/smart_ptr.hpp>

#include "map.hpp"
#include "key.hpp"
#include "cmd.hpp"

class StdScrModel
{

public:

	typedef boost::shared_ptr< std::string > line_ptr;

	typedef boost::shared_ptr< Map > map_ptr;
	typedef boost::shared_ptr< Command > cmd_ptr;
	typedef boost::shared_ptr< Key > key_ptr;

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

	void LoadCmd( const std::string& fileName )
	{
		cmd_->Load( fileName );
	}

	line_ptr GetPrompt();
	line_ptr NextLine( size_t line );

	map_ptr	GetMap();
	cmd_ptr GetCmd();
	key_ptr GetCmd();

private:

	map_ptr map_;
	cmd_ptr cmd_;
	key_ptr key_;

};

#endif

