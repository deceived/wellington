#ifndef STDSCR_MODEL_HPP
#define STDSCR_MODEL_HPP

#include "map_model.hpp"
#include "key_model.hpp"
#include "cmd_model.hpp"

class StdScrModel
{

public:

	typedef boost::shared_ptr< MapModel >	map_model;
	typedef boost::shared_ptr< KeyModel >	key_model;
	typedef boost::shared_ptr< CmdModel >	cmd_model;

	StdScrModel()
		: mapModel_( boost::make_shared< MapModel >() ),
		  keyModel_( boost::make_shared< KeyModel >() ),
		  cmdModel_( boost::make_shared< CmdModel >() )
	{}

	void LoadMap( const std::string& fileName )
	{
		mapModel_->Load( fileName );
	}

	void LoadKey( const std::string& fileName )
	{
		keyModel_->Load( fileName );
	}

	void LoadCmd( )
	{
	}

	map_model	GetMapModel()
	{
		return mapModel_;
	}

	key_model	GetKeyModel()
	{
		return keyModel_;
	}

	cmd_model	GetCmdModel()
	{
		return cmdModel_;
	}
	
private:

	map_model	mapModel_;
	key_model	keyModel_;
	cmd_model	cmdModel_;
};

#endif

