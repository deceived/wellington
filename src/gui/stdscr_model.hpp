#ifndef STDSCR_MODEL_HPP
#define STDSCR_MODEL_HPP

#include <boost/smart_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>

#include "logger.hpp"

#include "properties.hpp"
#include "map.hpp"
#include "key.hpp"
#include "cmd.hpp"
#include "tile.hpp"

#include "actor_factory.hpp"
#include "resource_cache.hpp"

extern Log logger;

class StdScrModel
{

public:

	typedef boost::shared_ptr< StdScrModel > model_ptr;

	typedef boost::shared_ptr< std::string > line_ptr;

	typedef boost::shared_ptr< Map > map_ptr;
	typedef boost::shared_ptr< Key > key_ptr;
	typedef boost::shared_ptr< Command > cmd_ptr;

	StdScrModel();

	void LoadMap( const std::string& fileName );
	void LoadKey( const std::string& fileName );
	void LoadCmd( const std::string& fileName );

	Properties::ptr Load( const std::string& fileName );

	map_ptr	GetMap();
	cmd_ptr GetCmd();
	key_ptr GetKey();

	std::vector<Tile> GetTiles();

private:

	map_ptr map_;
	key_ptr key_;
	cmd_ptr cmd_;

	std::vector< Tile > tiles_;
	std::vector< ActorPtr > actors_;

	ActorFactory actorFactory_;

	ResourceCache cache_;
	
	std::string mapFilename_;
	std::string mapKeyFilename_;
	float scale_;
	
};

#endif

