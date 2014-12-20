#ifndef STDSCR_MODEL_HPP
#define STDSCR_MODEL_HPP

#include <boost/smart_ptr.hpp>

#include "map.hpp"
#include "key.hpp"
#include "cmd.hpp"

class StdScrModel
{

public:

	typedef boost::shared_ptr< StdScrModel > model_ptr;

	typedef boost::shared_ptr< std::string > line_ptr;

	typedef boost::shared_ptr< Map > map_ptr;
	typedef boost::shared_ptr< Key > key_ptr;
	typedef boost::shared_ptr< Command > cmd_ptr;

	StdScrModel()
		: map_( boost::make_shared< Map >() ),
		  key_( boost::make_shared< Key >() ),
          cmd_( boost::make_shared< Command >() )
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

	map_ptr	GetMap()
	{
		return map_;
	}

	cmd_ptr GetCmd()
	{
		return cmd_;
	}

	key_ptr GetKey()
	{
		return key_;
	}


private:

	map_ptr map_;
	key_ptr key_;
	cmd_ptr cmd_;

};

#endif

