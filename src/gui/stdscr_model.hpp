#ifndef STDSCR_MODEL_HPP
#define STDSCR_MODEL_HPP

#include "map.hpp"
#include "key.hpp"
#include "cmd.hpp"

class StdScrModel
{

public:

	typedef boost::shared_ptr< Map >	map_type;
	typedef boost::shared_ptr< Key >	key_type;
	typedef boost::shared_ptr< Cmd >	cmd_type;

	StdScrModel()
		: mapModel_( boost::make_shared< Map >() ),
		  keyModel_( boost::make_shared< Key >() ),
		  cmdModel_( boost::make_shared< Cmd >() )
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

	map_model	GetMapModel()
	{
		return map_;
	}

	key_model	GetKeyModel()
	{
		return key_;
	}

	cmd_model	GetCmdModel()
	{
		return cmd_;
	}
	
private:

	map_type	map_;
	key_type	key_;
	cmd_type	cmd_;
};

#endif

